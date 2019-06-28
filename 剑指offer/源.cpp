#include<iostream>

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);

	CMyString& operator=(const CMyString& str);

	~CMyString();
private:
	char* m_pData;
};

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this == &str)
		return *this;

	delete[]m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData + 1)];
	strcpy(m_pData, str.m_pData);

	return *this;
}

//¿¼ÂÇÒì³£
CMyString& CMyString::operator=(const CMyString& str)
{
	if (this != &str)
	{
		CMyString strTemp(str);

		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}

	return *this;
}