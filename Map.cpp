#include <iostream>
#include <string>
#include "Map.h"

Map::Map()
{
	KeyVal m_keyvalue[DEFAULT_MAX_ITEMS];
	m_size = 0;
}

bool Map::empty() const
{
	return (m_size == 0);
}

int Map::size() const
{
	return m_size;
}

bool Map::insert(const KeyType& key, const ValueType& value)
{
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		if (key == m_keyvalue[i].key || m_size >= DEFAULT_MAX_ITEMS)
			return false;
	m_keyvalue[m_size].key = key;
	m_keyvalue[m_size].val = value;
	m_size++;
		return true;
}

bool Map::update(const KeyType& key, const ValueType& value)
{
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		if (key == m_keyvalue[i].key)
		{
			m_keyvalue[i].val = value;
			return true;
		}
	return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value)
{
	if (!update(key, value))
		if (!insert(key, value))
			return false;
	return true;
}

bool Map::erase(const KeyType& key)
{
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		if (key == m_keyvalue[i].key)
		{
			for (i; i < (DEFAULT_MAX_ITEMS); i++)
			{
				m_keyvalue[i] = m_keyvalue[i + 1];
			}
			m_size--;
			return true;
		}
	return false;
}

bool Map::contains(const KeyType& key) const
{
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		if (key == m_keyvalue[i].key)
		{
			return true;
		}
	return false;
}

bool Map::get(const KeyType& key, ValueType& value)
{
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		if (key == m_keyvalue[i].key)
		{
			value = m_keyvalue[i].val;
			return true;
		}
	return false;
}

bool Map::get(int i, KeyType& key, ValueType& value)
{
	if (i >= 0 && i < size())
	{
		key = m_keyvalue[i].key;
		value = m_keyvalue[i].val;
		return true;
	}
	return false;
}

void Map::swap(Map& other)
{
	KeyVal swapper[DEFAULT_MAX_ITEMS];
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
	{
	swapper[i].key = m_keyvalue[i].key;
	swapper[i].val = m_keyvalue[i].val;
	}
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
	{
		m_keyvalue[i].key = other.m_keyvalue[i].key;
		m_keyvalue[i].val = other.m_keyvalue[i].val;
	}
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
	{
		(other.m_keyvalue[i]).key = swapper[i].key;
		(other.m_keyvalue[i]).val = swapper[i].val;
	}
}

