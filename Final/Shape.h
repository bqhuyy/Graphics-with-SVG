#pragma once

#include "Attribute.h"

class Shape
{
protected:
	vector<Attribute*> attr;
	DataType fill, stroke, stroke_width, fill_opacity, stroke_opacity, trans;
	const vector<string> transformName = { "translate", "rotate", "scale" };
public:
	friend class ListOfShape;
	DataType find(string);
	virtual void init() = 0;
	void setAttribute(string, string);
	virtual void getAllAttribute() = 0;
	virtual VOID OnPaint(HDC) = 0;
	VOID OnTransform(Graphics&);
	virtual void input(xml_node<>*, const vector<pair<string, string>>&) { return; };
	virtual ~Shape();
};

class _Line : public Shape
{
private:
	const vector<string> attributeName = { "x1", "y1", "x2", "y2", "stroke", "stroke-width", "stroke-opacity", "transform" };
	DataType x1, y1, x2, y2;
public:
	void init();
	void getAllAttribute();
	VOID OnPaint(HDC);
};

class _Rect : public Shape
{
private:
	const vector<string> attributeName = { "x", "y", "width", "height", "fill", "stroke", "stroke-width", "fill-opacity", "stroke-opacity", "transform" };
	DataType x, y, width, height;
public:
	void init();
	void getAllAttribute();
	VOID OnPaint(HDC);
};

class _Circle : public Shape
{
private:
	const vector<string> attributeName = { "cx", "cy", "r", "fill", "stroke", "stroke-width", "fill-opacity", "stroke-opacity", "transform" };
	DataType cx, cy, r;
public:
	void init();
	void getAllAttribute();
	VOID OnPaint(HDC);
};

class _Ellipse : public Shape
{
private:
	const vector<string> attributeName = { "cx", "cy", "rx", "ry", "fill", "stroke", "stroke-width", "fill-opacity", "stroke-opacity", "transform" };
	DataType cx, cy, rx, ry;
public:
	void init();
	void getAllAttribute();
	VOID OnPaint(HDC);
};

class _Polyline : public Shape
{
private:
	const vector<string> attributeName = { "fill", "stroke", "stroke-width", "fill-opacity", "stroke-opacity", "points", "transform" };
	DataType points;
public:
	void init();
	void getAllAttribute();
	VOID OnPaint(HDC);
};

class _Polygon : public Shape
{
private:
	const vector<string> attributeName = { "fill", "stroke", "stroke-width", "fill-opacity", "stroke-opacity", "points", "transform" };
	DataType points;
public:
	void init();
	void getAllAttribute();
	VOID OnPaint(HDC);
};

class _Text : public Shape
{
private:
	const vector<string> attributeName = { "x", "y", "fill", "stroke", "stroke-width", "fill-opacity", "stroke-opacity", "transform", "font-size", "text" };
	DataType x, y, text, font_size;
public:
	void init();
	void getAllAttribute();
	VOID OnPaint(HDC);
};

class _Path : public Shape
{
private:
	const vector<string> commandName = { "M", "L", "H", "V", "C", "Z" };
	const vector<string> attributeName = { "fill", "stroke", "stroke-width", "fill-opacity", "stroke-opacity", "transform", "d" };
	DataType d;
public:
	void init();
	void getAllAttribute();
	VOID OnPaint(HDC);
};

class _Group : public Shape
{
private:
	const vector<string> shapeName = { "line", "rect", "circle", "ellipse", "polyline", "polygon", "text", "g", "path" };
	const vector<string> attributeName = { "fill", "stroke", "stroke-width", "fill-opacity", "stroke-opacity", "transform" };
	vector<Shape*> multiShape;
public:
	void init();
	void getAllAttribute();
	void input(xml_node<>*, const vector<pair<string, string>>&);
	VOID OnPaint(HDC);
	~_Group();
};

class ListOfShape
{
private:
	const vector<string> shapeName = { "line", "rect", "circle", "ellipse", "polyline", "polygon", "text", "g", "path" };
	vector<Shape*> list;
public:
	void inputFromSVG();
	void draw(HDC);
	~ListOfShape();
};