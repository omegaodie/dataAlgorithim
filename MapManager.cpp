#include "stdafx.h"
#include "MapManager.h"

// Constructor method for the MapManager (see step 2 in the assignment)
MapManager::MapManager()
{
	for(int i = 0; i < DemoConstants::COLUMNS* DemoConstants::ROWS; i++)
	{
		m_buckets[i] = list <CustomSprite  const*>();
	}
}

// Clear each entry in the map (step 3 in the assignment)
void MapManager::clearBucketLists()
{	
	// TODO: Implement logic here...
	for(int i = 0; i < DemoConstants::COLUMNS* DemoConstants::ROWS; i++)
	{
		m_buckets[i].clear();
	}
}

// Register the given sprite in the map (step 5 in the assignment)
void MapManager::registerSprite( CustomSprite const & sprite )
{
	SpriteHeight = sprite.getGlobalBounds().height;
	SpriteWidth = sprite.getGlobalBounds().width;
	list<int> cellIds = getBucketId( sprite );
	for(int i = 0; i < cellIds.size(); i++)
	{
		std::list<int>::iterator it = cellIds.begin();
		m_buckets[*it].push_back(&sprite);
		it++;
	}

}
	
// For each sprite corner, call the AddSpriteToBucket member function below. 
// See step 4 in the assignment for further details.
list<int> MapManager::getBucketId(CustomSprite const & sprite)
{
	// A list of bucket id's that the given sprite is in.
	list<int> bucketsSpriteIsIn;
	sf::Vector2f spritePos = sprite.getPosition();
	sf::Vector2f sC1;
	sf::Vector2f sC2;
	sf::Vector2f sC3;
	sf::Vector2f sC4;
	//get corners
	//
	sC1.x = spritePos.x - (SpriteWidth / 2);
	sC1.y = spritePos.y - (SpriteHeight / 2);
	sC2.x = spritePos.x + (SpriteWidth / 2);
	sC2.y = spritePos.y + (SpriteHeight / 2);
	sC3.x = spritePos.x + (SpriteWidth / 2);
	sC3.y = spritePos.y - (SpriteHeight / 2);
	sC4.x = spritePos.x - (SpriteWidth / 2);
	sC4.y = spritePos.y + (SpriteHeight / 2);


	//floor( spriteX / cell width ) + ( floor( spriteY / cell width ) * Number of Columns )
	for (int i = 0; i < 4; i++)
	{
		int add = floor(sC1.x / 200) + (floor(sC1.y / 200) * 4);
		bucketsSpriteIsIn.remove(add);
		bucketsSpriteIsIn.push_front(add);
		
	}


	//for (int i = 0; i < 4; i++)
	//{
	//	for(int j = 0; j < 4; j++)
	//	{
	//		bool iAdded = false;
	//		if(sC1.x > 200 * i && sC1.x < 200 * (i + 1) && (sC1. y > 200 * j && sC1.y < 200 * (j + 1)))
	//		{
	//			if (iAdded == false)
	//			{
	//				bucketsSpriteIsIn.push_front(i);
	//				iAdded = true;
	//			}	
	//		}
	//		if(sC2.x > 200 * i && sC2.x < 200 * (i + 1) && (sC2. y > 200 * j && sC2.y < 200 * (j + 1)))
	//		{
	//			if (iAdded == false)
	//			{
	//				bucketsSpriteIsIn.push_front(i);
	//				iAdded = true;
	//			}
	//		}
	//		if(sC3.x > 200 * i && sC3.x < 200 * (i + 1) && (sC3. y > 200 * j && sC3.y < 200 * (j + 1)))
	//		{
	//			if (iAdded == false)
	//			{
	//				bucketsSpriteIsIn.push_front(i);
	//				iAdded = true;
	//			}
	//		}	
	//		if(sC1. x > 200 * i && sC1.x < 200 * (i + 1) && (sC1. y > 200 * j && sC1.y < 200 * (j + 1)))
	//		{
	//			if (iAdded == false)
	//			{
	//				bucketsSpriteIsIn.push_front(i);
	//				iAdded = true;
	//			}
	//		}
	//	}
	//}
	return bucketsSpriteIsIn;
}

// For the given sprite corner, work out which bucket the sprite should be added to, then
//  add it's bucketid to the list.
void MapManager::addSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn ) 
{
	// TODO: Implement logic here...
}

// Returns a list of nearby sprites for the given sprite (step 6 in the assignment).
list<CustomSprite const *> MapManager::getNearbySprites( CustomSprite const & sprite ) 
{
	// The list of nearby sprites to return.
	list<CustomSprite const *> nearbySprites;
	//std::list<int>::iterator it = cellIds.begin();
	//m_buckets[*it].push_back(&sprite);
	
	
	return nearbySprites;
}
//std::list<std::list<double> >::iterator it = list.begin();
//std::advance(it, 3);
//std::list<double>::iterator it2 = (*it).begin();
//std::advance(it2, 3);
//double d = *it2;