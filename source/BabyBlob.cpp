/**
	\section LICENSE
	PirateBaby is Copyright (c)2011 Kevin Winfield-Pantoja

	This file is part of PirateBaby.

	PirateBaby is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	PirateBaby is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with PirateBaby.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
  * \file a Blob type baby
  * \author Kevin Winfield-Pantoja
*/
#include "BabyBlob.h"
#include "Sprite.h"
#include "Food.h"
#include "Cheese.h"
using Penjin::BabyBlob;
using Penjin::Sprite;
using Penjin::Food;
using Penjin::Cheese;

BabyBlob::BabyBlob()
{
    //ctor
    sprIdle->clear();
    sprIdle->load("images/blob.png",4,1);
    sprIdle->setPlayMode(pmNormal);
    sprIdle->setLooping(true);
    sprIdle->setFramesPerSecond(5);
    Vector2d<int> dim = GFX::getInstance()->getResolution();
    dim.x = dim.x / 2.5f;
    dim.y = dim.y / 2.25f;
    sprIdle->setPosition(dim);

    sprEat->clear();
    sprEat->load("images/blobeat.png",4,1);
    sprEat->setPlayMode(pmPulse);
    sprEat->setLooping(true);
    sprEat->setPosition(dim);

    sprWalkLeft->clear();
    sprWalkLeft->load("images/blobwalkleft.png",4,1);
    sprWalkLeft->setPlayMode(pmNormal);
    sprWalkLeft->setLooping(true);
    sprWalkLeft->setPosition(dim);

    sprWalkRight->clear();
    sprWalkRight->load("images/blobwalkright.png",4,1);
    sprWalkRight->setPlayMode(pmNormal);
    sprWalkRight->setLooping(true);
    sprWalkRight->setPosition(dim);

    sprActive = sprIdle;
    position = dim;
    action = ACTION_IDLE;

    illness = NULL;
}

BabyBlob::~BabyBlob()
{
    //dtor
    // Clean up shit
    for(uint i = 0; i < poops.size(); ++i)
        delete poops.at(i);

    delete illness;

    saveData();
}

string BabyBlob::getNextForm()
{
    return "";
}

void BabyBlob::interact(Prop* prop)
{

}

void BabyBlob::wash()
{
    Baby::wash();
    // Clean up shit
    for(uint i = 0; i < poops.size(); ++i)
    {
        delete poops.at(i);
        poops.at(i)=NULL;
    }
    poops.clear();
}

void BabyBlob::heal()
{
    Baby::heal();
    delete illness;
    illness = NULL;
}

void BabyBlob::eat(Food* f)
{
    if(f == NULL)
    {
        switchAction(ACTION_IDLE);
        return;
    }

    if(f->isOnFloor())
    {
        //  Walk towards the food
        int walkD = 0;
        int half = position.x + (sprActive->getDimensions().x *0.5f);
        int half2 = f->getPosition().x + (f->getDimensions().x * 0.5f);

        if(half > half2)
        {
            walkD = -1;
            switchAction(ACTION_WALK_LEFT);
        }
        else if(half < half2)
        {
            walkD = 1;
            switchAction(ACTION_WALK_RIGHT);
        }

        if(walkD != 0)
        {
            // Walk towards food
            position.x += walkD;
            sprActive->setPosition(position);
        }
        else if(sprActive->hitTest(f).hasCollided)
        {
            if(!f->isExhausted()
               && timer->getTicks()%60 ==1)
            {
                switchAction(ACTION_EAT);
                if(f->cNutrition < f->getNutrition())
                {
                    ++f->cNutrition;
                    if(hunger>0)
                        --hunger;
                }
                if(f->cWeight < f->getWeight())
                {
                    f->cWeight+=0.02f;
                    weight+=0.02f;
                }
                if(f->cWaste < f->getWaste())
                {
                    ++f->cWaste;
                    // fill up toilet meter
                    ++toilet;
                    // If toilet meter full, go to toilet
                    // going to toilet is dirty.
                    if(toilet>=100 && hygiene>0)
                    {
                        --hygiene;
                    }
                }
            }// !isExhausted
        }//hasCollided
    }// onFloor
    else
        switchAction(ACTION_IDLE);
}

void BabyBlob::render()
{
    for(uint i =0; i < poops.size(); ++i)
        poops.at(i)->render();
    Baby::render();
    if(illness)
        illness->render();
}

void BabyBlob::update()
{
    Baby::update();

    // We use energy walking
    if(action == ACTION_WALK_LEFT || action == ACTION_WALK_RIGHT)
    {
        // We also lose weight due to walking
        weight-=0.0001f;
    }

    // We also get hungry over time
    if(timer->getTicks()%600 == 1)
    {
        // If we are not at max hunger we increase
        if(hunger<100)
            ++hunger;
        // We lose weight if we are at max hunger
        else
            weight-=0.02f;

        // Check hygiene and illness.
        if(!poops.empty())
        {
            // We subtract for each poop
            for(int i = poops.size()-1; i>=0; --i)
                --hygiene;
        }

        // If we are so dirty, we are ill and lose health.
        if(hygiene <= 0)
        {
            hygiene = 0;
            switchAction(ACTION_ILL);
            if(illness == NULL)
            {
                illness = new Sprite;
                illness->load("images/illness.png",4,1);
                illness->setLooping(true);
                illness->setPosition(position);
            }
            --health;
        }
    }

    // Check toilet duties
    if(toilet>=100)
    {
        toilet = 0;
        Sprite* poop = NULL;
        poop = new Sprite;
        poop->load("images/poop.png");
        poop->setPosition(position);
        poops.push_back(poop);
        switchAction(ACTION_POOP);
    }

    if(illness)
    {
        illness->setPosition(position);
        illness->update();
    }

    //  Check death
    if(health<=0 || weight <= 0.0f)
        switchAction(ACTION_DIE);
}
