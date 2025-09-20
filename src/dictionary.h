#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <typename t1, typename t2>

class dictionary
{
private:
    struct value
    {
        t2 value;
    };
    struct key
    {
        int index;
        t1 key_value;
        value *ptr_key_value;
    };

public:
    vector<key *> keys;
    int current_index = 0;

    void insert(t1 para_key_value, t2 para_value)
    {
        key *ptr_to_key = new key;
        value *ptr_value = new value;

        ptr_to_key->index = current_index;
        ++current_index;

        ptr_to_key->key_value = para_key_value;
        ptr_to_key->ptr_key_value = ptr_value;

        keys.push_back(ptr_to_key);
        ptr_value->value = para_value;
    }
    t2 &operator[](const t1 search_key)
    {
        for (key *k : keys)
        {
            if (k->key_value == search_key)
            {
                return k->ptr_key_value->value;
            }
        }

        throw runtime_error("Key not found: " + search_key);
    }

    void delete_key(const t1 &search_key)
    {
        for (auto it = keys.begin(); it != keys.end(); ++it)
        {
            if ((*it)->key_value == search_key)
            {
                delete (*it)->ptr_key_value; // free
                delete *it;
                keys.erase(it);
                return;
            }
        }
        throw runtime_error("Key not found");
    }
    bool does_have(t1 key)
    {
        for (auto k : keys)
        {
            if (k->key_value == key)
            {
                return true;
            };
        }
        return false;
    }
    int size()
    {
        int size = keys.size();
        return size;
    }
    bool is_empty() const
    {
        return keys.empty();
    }
    void clear()
    {
        for (auto k : keys)
        {
            delete k->ptr_key_value;
            delete k;
        }
        keys.clear();
        current_index = 0;
    }
    void update(t1 search_key, t2 new_value)
    {
        for (auto k : keys)
        {
            if (k->key_value == search_key)
            {
                k->ptr_key_value->value = new_value;
                return;
            }
        }
        throw runtime_error("Key not found for update");
    }
    ~dictionary()
    {
        clear();
    }
};
