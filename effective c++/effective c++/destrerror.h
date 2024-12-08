#pragma once

class DBConnection
{
public:
	//必须写在类里面
	static DBConnection& create()
	{
		static DBConnection myDBConnection;
		return myDBConnection;
	}
	void close() {}
private:
	DBConnection();
};

class DBConn
{
public:
	void close()		//供客户调用
	{
		m_db.close();
		m_isclosed = true;
	}

	~DBConn()
	{
		if (!m_isclosed)
		{
			try { m_db.close(); }
			catch (...) {}
		}
	}
private:
	DBConnection m_db;
	bool m_isclosed;
};