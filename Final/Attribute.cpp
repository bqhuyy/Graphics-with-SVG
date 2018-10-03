#include "Attribute.h"

//DATA TYPE

void DataType::init()
{
	doubleVal = 0;
	colorVal = Color(255, 255, 255);
}

void DataType::setDouble(double x)
{
	doubleVal = x;
}

void DataType::setColor(Color x)
{
	colorVal = x;
}

void DataType::setPoint(vector<PointF> x)
{
	points = x;
}

void DataType::setTransform(pair<string, vector<float>> x)
{
	trans.push_back(x);
}

void DataType::setListCommand(pair<string, vector<float>> x)
{
	listC.push_back(x);
}

void DataType::setString(string x)
{
	s = x;
}

void DataType::setNone()
{
	none = true;
}

void DataType::setAccess()
{
	access = true;
}

double DataType::getDouble()
{
	return doubleVal;
}

const Color& DataType::getColor()
{
	return colorVal;
}

const vector<PointF>& DataType::getPoint()
{
	return points;
}

const vector<pair<string, vector<float>>>& DataType::getTransform()
{
	return trans;
}

const vector<pair<string, vector<float>>>& DataType::getListCommand()
{
	return listC;
}

const string& DataType::getString()
{
	return s;
}

bool DataType::getNone()
{
	return none;
}

bool DataType::getAccess()
{
	return access;
}

//Set Attribute

void _Double::setValue (string attr_value)
{
	val.setDouble(atof(attr_value.c_str()));
}

void _Color::setValue(string attr_value) //COLOR
{
	string tmp;
	val.setAccess();
	attr_value = toLower(attr_value);
	if (attr_value == "none")
	{
		val.setNone();
		return;
	}
	vector<float> res = getNumber(attr_value);
	val.setColor(Color(res[0], res[1], res[2]));
}

void _Point::setValue(string attr_value)
{
	attr_value = deleteSpace(attr_value);
	vector<float> tmp = getNumber(attr_value);
	vector<PointF> res;
	int size = tmp.size();
	for (int i = 0; i < size; i += 2)
		res.push_back(PointF(tmp[i], tmp[i + 1]));
	val.setPoint(res);
}

void _Transform::setValue(string attr_value)
{
	attr_value = toLower(attr_value);
	vector<string> f;
	vector<float> vecF;
	string name;
	f = splitString(attr_value);
	int size = f.size(), tmp;
	for (int i = 0; i < size; i++)
	{
		name = "";
		vecF.clear();
		vecF = getNumber(f[i], name);
		val.setTransform(make_pair(name, vecF));
	}
}

void _ListCommand::setValue(string attr_value)
{
	attr_value = deleteSpace(attr_value);
	vector<float> res = getNumber(attr_value), x;
	int length = attr_value.length(), size = res.size(), k = 0, commandSize = commandName.size();
	string tmp;
	for (int i = 0; i < length; i++)
	{
		x.clear();
		tmp = "";
		tmp += attr_value[i];
		for (int j = 0; j < commandSize; j++)
			if (tmp == commandName[j])
			{
				switch (j)
				{
				case 0: case 1:
					x.push_back(res[k++]);
					x.push_back(res[k++]);
					val.setListCommand(make_pair(tmp, x));
					break;
				case 2: case 3:
					x.push_back(res[k++]);
					val.setListCommand(make_pair(tmp, x));
					break;
				case 4:
					for (int t = 0; t < 6; t++)
						x.push_back(res[k++]);
					val.setListCommand(make_pair(tmp, x));
					break;
				case 5:
					val.setListCommand(make_pair(tmp, x));
				}
				break;
			}
	}
}

void _String::setValue(string attr_value)
{
	val.setString(attr_value);
}

//OTHER

string toLower(string s)
{
	int l = s.length();
	for (int i = 0; i < l; i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + ('a' - 'A');
	return s;
}

vector<string> splitString(string s)
{
	vector<string> res;
	string tmp = "";
	s += " ";
	int size = s.length();
	for (int i = 0; i < size; i++)
	{
		if (s[i] == ')')
		{
			tmp += s[i];
			res.push_back(tmp);
			tmp = "";
		}
		else if (s[i] != ' ')
			tmp += s[i];
	}
	return res;
}

vector<float> getNumber(string s, string &name) //Return name
{
	int size = s.length(), k;
	string tmp = "";
	vector<float> res;
	for (k = 0; k < size; k++)
	{
		if (s[k] == '(')
			break;
		name += s[k];
	}
	for (int i = k + 1; i < size; i++)
	{
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '.') || (s[i] == '-'))
			tmp += s[i];
		else if (tmp != "")
		{
			res.push_back(atof(tmp.c_str()));
			tmp = "";
		}
	}
	return res;
}

vector<float> getNumber(string s)
{
	vector<float> res;
	s += " ";
	int size = s.length();
	string tmp = "";
	for (int i = 0; i < size; i++)
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '.') || (s[i] == '-'))
			tmp += s[i];
		else if (tmp != "")
		{
			res.push_back(atof(tmp.c_str()));
			tmp = "";
		}
	return res;
}

string deleteSpace(string s)
{
	int size = s.length();
	while (size > 0 && s[0] == ' ')
	{
		s.erase(0, 1);
		size--;
	}
	while (size > 0 && s[size - 1] == ' ')
	{
		s.erase(size - 1, 1);
		size--;
	}
	for (int i = 0; i < size; i++)
		if (s[i] == ' ' || s[i] == ',')
		{
			while (i + 1 < size && s[i + 1] == ' ')
			{
				s.erase(i + 1, 1);
				size--;
			}
			if (i + 1 < size && s[i + 1] == ',')
				s.erase(i, 1);
		}
	return s;
}