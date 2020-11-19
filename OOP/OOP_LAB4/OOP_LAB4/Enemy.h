#pragma once

class IEnemy {
public:
	virtual void Update() = 0;
	virtual void CollideWithPlayer() = 0;
};

template<typename TUpdate, typename TCollideWithPlayer>
class Enemy: public IEnemy
{
	TUpdate m_UpdateBehaviour;
	TCollideWithPlayer m_CollideWithPlayerBehaviour;
public:
	virtual void Update() {
		m_UpdateBehaviour.Update();
	}
	virtual void CollideWithPlayer() {
		m_CollideWithPlayerBehaviour.CollideWithPlayer();
	}
};

//Game g;
//g.SetEnemy(new Enemt<UpdateA, CollideTypeB>());

