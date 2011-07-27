//  Paul Reny - COMP 15 - 07/24/11
//  HW3
//  ptrie.h
//
//  Copyright 2011 Reny Design. All rights reserved.
//
//
//

#ifndef PTRIE_H
#define PTRIE_H

#include <string>

namespace preny {

  typedef unsigned int UInt32;
  typedef std::numeric_limits<UInt32> UInt32Limits;

class ptrie
{
public:
  static const UInt32 INVALID_VALUE = static_cast<UInt32>(-1);

  static const int AtoZ = 26 * 8;
  
  ptrie() {}
  virtual ~ptrie{}
  
  virtual bool build(const ptrie &trie) = 0;
  
  bool find(const char *key, UInt32 *value_ptr = NULL) const;
  bool find(const char *key, UInt32 length, UInt32 *value_ptr = NULL) const;
  
  bool follow(UInt32 index, const char *seq, UInt32 *index_ptr) const;
  bool follow(UInt32 index, const char *seq, UInt32 length,
              UInt32 *index_ptr) const;
  
  virtual UInt32 find_child(UInt32 index, UInt8 child_label) const = 0;
  
  virtual UInt32 child(UInt32 index) const = 0;
  virtual UInt32 sibling(UInt32 index) const = 0;
  virtual UInt8 label(UInt32 index) const = 0;
  
  virtual bool get_value(UInt32 index, UInt32 *value_ptr = NULL) const = 0;
  bool has_value(UInt32 index) const;
  UInt32 value(UInt32 index) const;
  
  UInt32 root() const;
  
  virtual UInt32 num_units() const = 0;
  virtual UInt32 num_nodes() const = 0;
  virtual UInt32 num_keys() const = 0;
  virtual UInt32 size() const = 0;
  
  virtual void clear() = 0;
  virtual void *map(void *addr) = 0;
  virtual bool read(std::istream *input) = 0;
  virtual bool write(std::ostream *output) const = 0;
  
private:
  // Disallows copies.
  TrieBase(const TrieBase &);
  TrieBase &operator=(const TrieBase &);
};

inline bool TrieBase::find(const char *key, UInt32 *value_ptr) const
{
  assert(key != NULL);
  
  UInt32 index;
  if (!follow(root(), key, &index))
    return false;
  
  return get_value(index, value_ptr);
}

inline bool TrieBase::find(const char *key, UInt32 length,
                           UInt32 *value_ptr) const
{
  assert(key != NULL || length == 0);
  
  UInt32 index;
  if (!follow(root(), key, length, &index))
    return false;
  
  return get_value(index, value_ptr);
}

inline bool TrieBase::follow(UInt32 index, const char *seq,
                             UInt32 *index_ptr = NULL) const
{
  assert(index < num_units());
  assert(seq != NULL);
  
  while (*seq != '\0')
  {
    index = find_child(index, *seq);
    if (index == 0)
      return false;
    ++seq;
  }
  if (index_ptr != NULL)
    *index_ptr = index;
  return true;
}

inline bool TrieBase::follow(UInt32 index, const char *seq,
                             UInt32 length, UInt32 *index_ptr = NULL) const
{
  assert(index < num_units());
  assert(seq != NULL || length == 0);
  
  for (UInt32 i = 0; i < length; ++i)
  {
    index = find_child(index, seq[i]);
    if (index == 0)
      return false;
  }
  if (index_ptr != NULL)
    *index_ptr = index;
  return true;
}

inline bool TrieBase::has_value(UInt32 index) const
{
  assert(index < num_units());
  
  return get_value(index);
}

inline UInt32 TrieBase::value(UInt32 index) const
{
  assert(index < num_units());
  
  UInt32 value = INVALID_VALUE;
  get_value(index, &value);
  return value;
}

inline UInt32  TrieBase::root() const { return 0; }

}  // namespace sumire

  
  
};

/*
template <typename VALUE, int RANGE, typename KEYTYPE>
struct ptrie
{
  typedef VALUE value_t;
  enum
  {
    range_mask = RANGE-1,
    range = RANGE
  };
  typedef KEYTYPE key_t;
  typedef ptrie<VALUE,RANGE,KEYTYPE> type_t;
  
  value_t result;
  type_t * parent;
  type_t * table[RANGE];
  
  
  struct iterator_callback
  {
    virtual bool operator() ( key_t *key, int len, value_t value) = 0;    
  };
  
  
  inline ptrie()
  : result(),
  parent(0)
  {
    for (int i=0; i<range; ++i)
    {
      table[i] = 0;
    }
  }
  
  
  inline ptrie( type_t * parent_ )
  : result(),
  parent( parent_ )
  {
    for (int i=0; i<range; ++i)
    {
      table[i] = 0;
    }
  }
  
  
  inline ~ptrie()
  {
    for (int i=0; i<range; ++i)
    {
      if ( table[i] )
        delete table[i];
    }
  }
  
  
  inline void add( const key_t *buf, int len, value_t v )
  {
    type_t * t = this;
    
    while( len-- )
    {
      key_t c = (*buf)&range_mask;
      
      if ( !t->table[c] )
      {
        t->table[c] = new type_t(t);
      }
      t = t->table[c];
      ++buf;
    }
    t->result = v;
  }
  
  
  inline value_t find( const key_t *buf, int len )
  {
    type_t * t = this;
    
    while( len-- )
    {
      t = t->table[ *(buf++)&(range_mask) ];
      if (!t)
        return 0;
    }
    return t->result;
  }
  
  
  inline const value_t find( const key_t *buf, int len ) const
  {
    type_t * t = this;
    
    while( len-- )
    {
      t = t->table[ *(buf++)&(range_mask) ];
      if (!t)
      {
        return 0;
      }
    }
    return t->result;
  }
  
  
  inline bool remove( const key_t *buf, int len )
  {
    type_t * last_fork = this;
    int last_fork_pos = 0;
    int pos = 0;
    type_t * t = this;
    
    // follow the branch but remember where the last fork in the branch is
    
    while ( len-- )
    {
      int entry_count = 0;
      for (int i=0; i<range; ++i)
      {
        entry_count += (int)(t->table[i]!=0);
      }
      
      if ( entry_count > 1 )
      {
        last_fork_pos = pos;
        last_fork = t;
      }
      
      t->table[ buf[pos]&(range_mask) ];
      if ( !t )
      {
        return false;
      }
      ++pos;
    }
    
    // ok, found a match, now delete the branch starting from our last fork position
    
    type_t **kill_point = &last_fork->table[ buf[last_fork_pos]&(range_mask) ];
    delete *kill_point;
    *kill_point = 0;
    
    return true;
  }
  
  
  inline bool iterate( key_t *buf, int max_len, iterator_callback &cb, int buf_pos=0 )
  {
    if( buf_pos >= max_len )
    {
      return false;
    }
    
    if( buf_pos > 0 )
    {
      if( !cb( buf, buf_pos, result ) )
      {
        return false;
      }
    }
    
    for( int i=0; i<range; ++i)
    {
      if( table[i] )
      {
        buf[buf_pos] = i;
        if( !table[i]->iterate( buf, max_len, cb, buf_pos+1 ) )
        {
          return false;
        }
      }
    }
    return true;
  }
};

*/
}
#endif










