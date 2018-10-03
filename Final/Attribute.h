#include "lib.h"

class DataType
{
private:
	double doubleVal;
	Color colorVal;
	vector<PointF> points;
	vector<pair<string, vector<float>>> trans, listC;
	string s;
	bool none, access;
public:
	DataType() : doubleVal(0), colorVal(Color(0, 0, 0)), s(""), none(false), access(false) {}
	DataType(double _doubleVal) : doubleVal(_doubleVal), colorVal(Color(0, 0, 0)), s(""), none(false), access(false) {}
	DataType(double r, double g, double b) : doubleVal(0), colorVal(Color(r, g, b)), s(""), none(false), access(false) {}
	DataType(string _s) : doubleVal(0), colorVal(Color(0, 0, 0)), s(_s), none(false), access(false) {}
	void init();
	void setDouble(double);
	void setColor(Color);
	void setPoint(vector<PointF>);
	void setTransform(pair<string, vector<float>>);
	void setListCommand(pair<string, vector<float>>);
	void setString(string);
	void setNone();
	void setAccess();
	double getDouble();
	const Color& getColor();
	const vector<PointF>& getPoint();
	const vector<pair<string, vector<float>>>& getTransform();
	const vector<pair<string, vector<float>>>& getListCommand();
	const string& getString();
	bool getNone();
	bool getAccess();
};

class Attribute
{
private:
	string name = "";
protected:
	DataType val;
public:
	Attribute() {}
	Attribute(const string& _name) : name(_name) {}
	Attribute(const string& _name, double _val) : name(_name), val(_val) {}
	Attribute(const string& _name, double r, double g, double b) : name(_name), val(r, g, b) {}
	const string& getName() { return name; }
	const DataType& getValue() { return val; }
	virtual void setValue(string) = 0;
	friend class Shape;
};

class _Double : public Attribute
{
public:
	_Double() {}
	_Double(const string& _name) : Attribute(_name) {}
	_Double(const string& _name, double _val) : Attribute(_name, _val) {}
	void setValue(string);
};

class _Color : public Attribute
{
public:
	_Color() {}
	_Color(const string& _name) : Attribute(_name) {}
	_Color(const string& _name, double r, double g, double b) : Attribute(_name, r, g, b) {}
	void setValue(string);
};

class _Point : public Attribute
{
public:
	_Point() {}
	_Point(const string& _name) : Attribute(_name) {}
	void setValue(string);
};

class _Transform : public Attribute
{
public:
	_Transform() {}
	_Transform(const string& _name) : Attribute(_name) {}
	void setValue(string);
};

class _String : public Attribute
{
public:
	_String() {}
	_String(const string& _name) : Attribute(_name) {}
	void setValue(string);
};

class _ListCommand : public Attribute
{
private:
	const vector<string> commandName = { "M", "L", "H", "V", "C", "Z" };
public:
	_ListCommand() {}
	_ListCommand(const string& _name) : Attribute(_name) {}
	void setValue(string);
};

string toLower(string);
vector<string> splitString(string);

//USE
vector<float> getNumber(string, string&); //Input string, return name

//USE FOR PATH
vector<float> getNumber(string);
string deleteSpace(string);