#include "Cage.h"
#include <iostream>
#include "AddScoresPlayerLogic.h"
#include "DeathLogic.h"
#include "TeleportPlayerLogic.h"


Cage::Cage()
{
	this->m_Type = REG;
	this->m_Pass = true;
	m_PlayerLogic = 0;
}

Cage::~Cage() {
	delete m_PlayerLogic;
}

void Cage::ReCage(CageType _type)
{
	m_Type = _type;
}

CageType Cage::GetType()
{
	return m_Type;
}

IPlayerLogic& Cage::SetPlayerLogic(IPlayerLogic* logic)
{
	m_PlayerLogic = logic;
	return *m_PlayerLogic;
}

Cage& Cage::operator+(Player& player)
{
	if (!m_PlayerLogic) return *this;
	m_PlayerLogic->Invoke(player);
	return *this;
}

std::ostream& operator<<(std::ostream& os, Cage& cage)
{
	switch (cage.m_Type)
	{
	case CageType::IN:
		return os << "1";
	case CageType::OUT:
		return os << "2";
	default:
		if (!cage.m_PlayerLogic) return os << ' ';
		else return cage.m_PlayerLogic->Print(os);
	}
}

Cage& Cage::operator = (const Cage& c) // оп-р копирования
{
	m_Pass = c.m_Pass;
	m_Type = c.m_Type;
	m_PlayerLogic = c.m_PlayerLogic;
	return *this;
}

void Cage::Save(std::ostream& os)
{
	os << m_Type << ' ' << m_Pass << ' ';
	if (!m_PlayerLogic) os << '0' << ' ';
	else m_PlayerLogic->Save(os);
	os << "   ";
}

void Cage::Load(std::istream& is) {
	int intType;
	is >> intType;
	if (intType < 0 || intType>2) throw "Unexpected CageType id";
	m_Type = (CageType)intType;
	is >> m_Pass;
	int playerLogicId;
	is >> playerLogicId;

	switch (playerLogicId)
	{
	case 0: m_PlayerLogic = 0; break;
	case IPlayerLogic::DEATH_LOGIC_ID: m_PlayerLogic = new DeathLogic(); break;
	case IPlayerLogic::ADD_SCORES_LOGIC_ID: m_PlayerLogic = new AddScoresPlayerLogic(is); break;
	case IPlayerLogic::TELEPORT_LOGIC_ID: m_PlayerLogic = new TeleportPlayerLogic(); break;
	default: throw "Unexpected player logic id";
	}	
}