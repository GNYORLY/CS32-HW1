#include <iostream>

typedef double ValueType;
typedef std::string KeyType;
const int DEFAULT_MAX_ITEMS = 200;

class Map
{
public:
	Map();         // Create an empty map (i.e., one with no key/value pairs)

	bool empty() const;  // Return true if the map is empty, otherwise false.

	int size() const;    // Return the number of key/value pairs in the map.

	bool insert(const KeyType& key, const ValueType& value);
	// If key is not equal to any key currently in the map, and if the
	// key/value pair can be added to the map, then do so and return true.
	// Otherwise, make no change to the map and return false (indicating
	// that either the key is already in the map, or the map has a fixed
	// capacity and is full).

	bool update(const KeyType& key, const ValueType& value);
	// If key is equal to a key currently in the map, then make that key no
	// longer map to the value it currently maps to, but instead map to
	// the value of the second parameter; return true in this case.
	// Otherwise, make no change to the map and return false.

	bool insertOrUpdate(const KeyType& key, const ValueType& value);
	// If key is equal to a key currently in the map, then make that key no
	// longer map to the value it currently maps to, but instead map to
	// the value of the second parameter; return true in this case.
	// If key is not equal to any key currently in the map and if the
	// key/value pair can be added to the map, then do so and return true.
	// Otherwise, make no change to the map and return false (indicating
	// that the key is not already in the map and the map has a fixed
	// capacity and is full).

	bool erase(const KeyType& key);
	// If key is equal to a key currently in the map, remove the key/value
	// pair with that key from the map and return true.  Otherwise, make
	// no change to the map and return false.

	bool contains(const KeyType& key) const;
	// Return true if key is equal to a key currently in the map, otherwise
	// false.

	bool get(const KeyType& key, ValueType& value);
	// If key is equal to a key currently in the map, set value to the
	// value in the map that that key maps to, and return true.  Otherwise,
	// make no change to the value parameter of this function and return
	// false.

	bool get(int i, KeyType& key, ValueType& value);
	// If 0 <= i < size(), copy into the key and value parameters the
	// key and value of one of the key/value pairs in the map and return
	// true.  Otherwise, leave the key and value parameters unchanged and
	// return false.  (See below for details about this function.)

	void swap(Map& other);
	// Exchange the contents of this map with the other one.
private:
	KeyVal m_keyvalue[];
};

struct KeyVal
{
public:
	KeyType name = "";
	ValueType number = 0;
};

Map::Map()
{
	KeyVal m_keyvalue[DEFAULT_MAX_ITEMS];
}

bool Map::empty() const
{

}

int Map::size() const
{
	int size = 0;
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		if (m_keyvalue[i].name != "")
			size++;
	return size;
}

bool Map::insert(const KeyType& key, const ValueType& value)
{
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		if (key == m_keyvalue[i].name)
			return false;
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		if (m_keyvalue[i].name == "" && m_keyvalue[i].number == 0)
		{
			m_keyvalue[i].name = key;
			m_keyvalue[i].number = value;
			return true;
		}	
	return false;
}

bool Map::update(const KeyType& key, const ValueType& value)
{
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		if (key == m_keyvalue[i].name)
		{
			m_keyvalue[i].number = value;
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
		if (key == m_keyvalue[i].name)
		{
			m_keyvalue[i].name = "";
			m_keyvalue[i].number = 0;
			return true;
		}
	return false;
}

bool Map::contains(const KeyType& key) const
{
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		if (key == m_keyvalue[i].name)
		{
			return true;
		}
	return false;
}

bool Map::get(const KeyType& key, ValueType& value)
{
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		if (key == m_keyvalue[i].name)
		{
			value = m_keyvalue[i].number;
			return true;
		}
	return false;
}

bool Map::get(int i, KeyType& key, ValueType& value)
{
	if (i >= 0 && i < size())
	{
		key = m_keyvalue[i].name;
		value = m_keyvalue[i].number;
	}
}

void Map::swap(Map& other)
{
	KeyVal swapper[DEFAULT_MAX_ITEMS];
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
	{
	swapper[i].name = m_keyvalue[i].name;
	swapper[i].number = m_keyvalue[i].number;
	}
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
	{
		m_keyvalue[i].name = other.m_keyvalue[i].name;
		m_keyvalue[i].number = other.m_keyvalue[i].number;
	}
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
	{
		(other.m_keyvalue[i]).name = swapper[i].name;
		(other.m_keyvalue[i]).number = swapper[i].number;
	}
}

