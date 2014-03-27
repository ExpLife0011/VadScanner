/**
 * @file Singleton.hpp
 * @author created by: Peter Hlavaty
 */

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

/*
# CSingleton usage : 

class CClass :
	public CSingleton<CClass>
{
	static CClass m_instance;
	CClass(...) : CSingleton(m_instance)
	{
	}
public:
}

CClass CClass::m_instance;
*/

template<class TYPE>
class CSingleton
{
	CSingleton(const CSingleton&);// = delete;
	void operator=(CSingleton const&);// = delete;
	static TYPE* m_instancePtr;
public:
	static
	TYPE& GetInstance()
	{
		return *m_instancePtr;
	}

protected:
	CSingleton(
		__in TYPE& staticInstance
		)
	{
		m_instancePtr = &staticInstance;
	}
};

template<class TYPE>
TYPE* CSingleton<TYPE>::m_instancePtr = NULL;

#endif //__SINGLETON_H__
