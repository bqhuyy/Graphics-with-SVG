#include "Shape.h"

//DESTRUCTOR

Shape::~Shape()
{
	int size = attr.size();
	for (int i = 0; i < size; i++)
		delete attr[i];
	attr.clear();
}

ListOfShape::~ListOfShape()
{
	int size = list.size();
	for (int i = 0; i < size; i++)
		delete list[i];
	list.clear();
}

_Group::~_Group()
{
	int size = multiShape.size();
	for (int i = 0; i < size; i++)
		delete multiShape[i];
	multiShape.clear();
}

//INIT

void _Line::init()
{
	attr.push_back(new _Double(attributeName[0]));
	attr.push_back(new _Double(attributeName[1]));
	attr.push_back(new _Double(attributeName[2]));
	attr.push_back(new _Double(attributeName[3]));
	attr.push_back(new _Color(attributeName[4], 255, 255, 255));
	attr.push_back(new _Double(attributeName[5], 1));
	attr.push_back(new _Double(attributeName[6], 1));
	attr.push_back(new _Transform(attributeName[7]));
}

void _Rect::init()
{
	attr.push_back(new _Double(attributeName[0]));
	attr.push_back(new _Double(attributeName[1]));
	attr.push_back(new _Double(attributeName[2]));
	attr.push_back(new _Double(attributeName[3]));
	attr.push_back(new _Color(attributeName[4], 0, 0, 0));
	attr.push_back(new _Color(attributeName[5], 255, 255, 255));
	attr.push_back(new _Double(attributeName[6], 1));
	attr.push_back(new _Double(attributeName[7], 1));
	attr.push_back(new _Double(attributeName[8], 1));
	attr.push_back(new _Transform(attributeName[9]));
}

void _Circle::init()
{
	attr.push_back(new _Double(attributeName[0]));
	attr.push_back(new _Double(attributeName[1]));
	attr.push_back(new _Double(attributeName[2]));
	attr.push_back(new _Color(attributeName[3], 0, 0, 0));
	attr.push_back(new _Color(attributeName[4], 255, 255, 255));
	attr.push_back(new _Double(attributeName[5], 1));
	attr.push_back(new _Double(attributeName[6], 1));
	attr.push_back(new _Double(attributeName[7], 1));
	attr.push_back(new _Transform(attributeName[8]));
}

void _Ellipse::init()
{
	attr.push_back(new _Double(attributeName[0]));
	attr.push_back(new _Double(attributeName[1]));
	attr.push_back(new _Double(attributeName[2]));
	attr.push_back(new _Double(attributeName[3]));
	attr.push_back(new _Color(attributeName[4], 0 ,0 ,0));
	attr.push_back(new _Color(attributeName[5], 255, 255, 255));
	attr.push_back(new _Double(attributeName[6], 1));
	attr.push_back(new _Double(attributeName[7], 1));
	attr.push_back(new _Double(attributeName[8], 1));
	attr.push_back(new _Transform(attributeName[9]));
}

void _Polyline::init()
{
	attr.push_back(new _Color(attributeName[0], 0, 0, 0));
	attr.push_back(new _Color(attributeName[1], 255, 255, 255));
	attr.push_back(new _Double(attributeName[2], 1));
	attr.push_back(new _Double(attributeName[3], 1));
	attr.push_back(new _Double(attributeName[4], 1));
	attr.push_back(new _Point(attributeName[5]));
	attr.push_back(new _Transform(attributeName[6]));
}

void _Polygon::init()
{
	attr.push_back(new _Color(attributeName[0], 0, 0, 0));
	attr.push_back(new _Color(attributeName[1], 255, 255, 255));
	attr.push_back(new _Double(attributeName[2], 1));
	attr.push_back(new _Double(attributeName[3], 1));
	attr.push_back(new _Double(attributeName[4], 1));
	attr.push_back(new _Point(attributeName[5]));
	attr.push_back(new _Transform(attributeName[6]));
}

void _Text::init()
{
	attr.push_back(new _Double(attributeName[0]));
	attr.push_back(new _Double(attributeName[1]));
	attr.push_back(new _Color(attributeName[2], 0, 0, 0));
	attr.push_back(new _Color(attributeName[3], 255, 255, 255));
	attr.push_back(new _Double(attributeName[4], 1));
	attr.push_back(new _Double(attributeName[5], 1));
	attr.push_back(new _Double(attributeName[6], 1));
	attr.push_back(new _Transform(attributeName[7]));
	attr.push_back(new _Double(attributeName[8]));
	attr.push_back(new _String(attributeName[9]));
}

void _Group::init()
{
	attr.push_back(new _Color(attributeName[0], 0, 0, 0));
	attr.push_back(new _Color(attributeName[1], 255, 255, 255));
	attr.push_back(new _Double(attributeName[2], 1));
	attr.push_back(new _Double(attributeName[3], 1));
	attr.push_back(new _Double(attributeName[4], 1));
	attr.push_back(new _Transform(attributeName[5]));
}

void _Path::init()
{
	attr.push_back(new _Color(attributeName[0], 0, 0, 0));
	attr.push_back(new _Color(attributeName[1], 255, 255, 255));
	attr.push_back(new _Double(attributeName[2], 1));
	attr.push_back(new _Double(attributeName[3], 1));
	attr.push_back(new _Double(attributeName[4], 1));
	attr.push_back(new _Transform(attributeName[5]));
	attr.push_back(new _ListCommand(attributeName[6]));
}

//GET ALL ATTRIBUTE IN TO DERIVED CLASS

void _Line::getAllAttribute()
{
	x1 = find(attributeName[0]);
	y1 = find(attributeName[1]);
	x2 = find(attributeName[2]);
	y2 = find(attributeName[3]);
	stroke = find(attributeName[4]);
	stroke_width = find(attributeName[5]);
	stroke_opacity = find(attributeName[6]);
	trans = find(attributeName[7]);
	if (!stroke.getAccess())
		stroke.setNone();
}

void _Rect::getAllAttribute()
{
	x = find(attributeName[0]);
	y = find(attributeName[1]);
	width = find(attributeName[2]);
	height = find(attributeName[3]);
	fill = find(attributeName[4]);
	stroke = find(attributeName[5]);
	stroke_width = find(attributeName[6]);
	fill_opacity = find(attributeName[7]);
	stroke_opacity = find(attributeName[8]);
	trans = find(attributeName[9]);
	if (!stroke.getAccess())
		stroke.setNone();
}

void _Circle::getAllAttribute()
{
	cx = find(attributeName[0]);
	cy = find(attributeName[1]);
	r = find(attributeName[2]);
	fill = find(attributeName[3]);
	stroke = find(attributeName[4]);
	stroke_width = find(attributeName[5]);
	fill_opacity = find(attributeName[6]);
	stroke_opacity = find(attributeName[7]);
	trans = find(attributeName[8]);
	if (!stroke.getAccess())
		stroke.setNone();
}

void _Ellipse::getAllAttribute()
{
	cx = find(attributeName[0]);
	cy = find(attributeName[1]);
	rx = find(attributeName[2]);
	ry = find(attributeName[3]);
	fill = find(attributeName[4]);
	stroke = find(attributeName[5]);
	stroke_width = find(attributeName[6]);
	fill_opacity = find(attributeName[7]);
	stroke_opacity = find(attributeName[8]);
	trans = find(attributeName[9]);
	if (!stroke.getAccess())
		stroke.setNone();
}

void _Polyline::getAllAttribute()
{
	fill = find(attributeName[0]);
	stroke = find(attributeName[1]);
	stroke_width = find(attributeName[2]);
	fill_opacity = find(attributeName[3]);
	stroke_opacity = find(attributeName[4]);
	points = find(attributeName[5]);
	if (!stroke.getAccess())
		stroke.setNone();
}

void _Polygon::getAllAttribute()
{
	fill = find(attributeName[0]);
	stroke = find(attributeName[1]);
	stroke_width = find(attributeName[2]);
	fill_opacity = find(attributeName[3]);
	stroke_opacity = find(attributeName[4]);
	points = find(attributeName[5]);
	trans = find(attributeName[6]);
	if (!stroke.getAccess())
		stroke.setNone();
}

void _Text::getAllAttribute()
{
	x = find(attributeName[0]);
	y = find(attributeName[1]);
	fill = find(attributeName[2]);
	stroke = find(attributeName[3]);
	stroke_width = find(attributeName[4]);
	fill_opacity = find(attributeName[5]);
	stroke_opacity = find(attributeName[6]);
	trans = find(attributeName[7]);
	font_size = find(attributeName[8]);
	text = find(attributeName[9]);
	if (!stroke.getAccess())
		stroke.setNone();
}

void _Group::getAllAttribute()
{
	fill = find(attributeName[0]);
	stroke = find(attributeName[1]);
	stroke_width = find(attributeName[2]);
	fill_opacity = find(attributeName[3]);
	stroke_opacity = find(attributeName[4]);
	trans = find(attributeName[5]);
}

void _Path::getAllAttribute()
{
	fill = find(attributeName[0]);
	stroke = find(attributeName[1]);
	stroke_width = find(attributeName[2]);
	fill_opacity = find(attributeName[3]);
	stroke_opacity = find(attributeName[4]);
	trans = find(attributeName[5]);
	d = find(attributeName[6]);
}

//INPUT GROUP

void _Group::input(xml_node<>* root_node, const vector<pair<string, string>>& myVec)
{
	DataType tmp;
	int size, k = 0;
	string text;
	vector<pair<string, string>> tmpVec;
	for (xml_node<> * node = root_node->first_node(); node; node = node->next_sibling())
	{
		tmpVec = myVec;
		size = shapeName.size();
		for (int i = 0; i < size; i++)
			if (shapeName[i] == node->name())
			{
				switch (i)
				{
				case 0: multiShape.push_back(new _Line); break;
				case 1: multiShape.push_back(new _Rect); break;
				case 2: multiShape.push_back(new _Circle); break;
				case 3: multiShape.push_back(new _Ellipse); break;
				case 4: multiShape.push_back(new _Polyline); break;
				case 5: multiShape.push_back(new _Polygon); break;
				case 6: multiShape.push_back(new _Text); break;
				case 7: multiShape.push_back(new _Group); break;
				case 8: multiShape.push_back(new _Path); break;
				}
				multiShape[k]->init();
				break;
			}
		size = tmpVec.size();
		for (int i = 0; i < size; i++)
			multiShape[k]->setAttribute(tmpVec[i].first, tmpVec[i].second);
		if (node->name() == string("text"))
			multiShape[k]->setAttribute(node->name(), node->value());
		while (node->first_attribute())
		{
			if (node->name() == string("g"))
				tmpVec.push_back(make_pair(node->first_attribute()->name(), node->first_attribute()->value()));
			multiShape[k]->setAttribute(node->first_attribute()->name(), node->first_attribute()->value());
			node->remove_first_attribute();
		}
		multiShape[k]->getAllAttribute();
		if (node->name() == string("g"))
			multiShape[k]->input(node, tmpVec);
		k++;
	}
}


//FIND

DataType Shape::find(string src)
{
	int size = attr.size();
	DataType res;
	for (int i = 0; i < size; i++)
		if (attr[i]->getName() == src)
		{
			res = attr[i]->getValue();
			break;
		}
	return res;
}

//ON TRANSFORM

VOID Shape::OnTransform(Graphics &graphics)
{
	vector<pair<string, vector<float>>> f = trans.getTransform();
	int n1 = f.size(), n2 = transformName.size(), n3;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			if (f[i].first == transformName[j])
			{
				switch (j)
				{
				case 0: graphics.TranslateTransform(f[i].second[0], f[i].second[1]); break;
				case 1: graphics.RotateTransform(f[i].second[0]); break;
				case 2:
					n3 = f[i].second.size();
					if (n3 == 1)
						graphics.ScaleTransform(f[i].second[0], f[i].second[0]);
					else graphics.ScaleTransform(f[i].second[0], f[i].second[1]);
					break;
				}
				break;
			}
}

//ON PAINT

VOID _Line::OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	graphics.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
	graphics.SetPixelOffsetMode(PixelOffsetModeHalf);
	OnTransform(graphics);
	Pen pen(Color(255 * stroke_opacity.getDouble(), stroke.getColor().GetR(), stroke.getColor().GetG(), stroke.getColor().GetB()), stroke_width.getDouble());
	if (!stroke.getNone())
		graphics.DrawLine(&pen, (int)x1.getDouble(), (int)y1.getDouble(), (int)x2.getDouble(), (int)y2.getDouble());
}

VOID _Rect::OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	graphics.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
	graphics.SetPixelOffsetMode(PixelOffsetModeHalf);
	OnTransform(graphics);
	Pen pen(Color(255 * stroke_opacity.getDouble(), stroke.getColor().GetR(), stroke.getColor().GetG(), stroke.getColor().GetB()), stroke_width.getDouble());
	SolidBrush brush(Color(255 * fill_opacity.getDouble(), fill.getColor().GetR(), fill.getColor().GetG(), fill.getColor().GetB()));
	if (!fill.getNone())
		graphics.FillRectangle(&brush, (int)x.getDouble(), (int)y.getDouble(), (int)width.getDouble(), (int)height.getDouble());
	if (!stroke.getNone())
		graphics.DrawRectangle(&pen, (int)x.getDouble(), (int)y.getDouble(), (int)width.getDouble(),(int)height.getDouble());
}

VOID _Circle::OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	graphics.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
	graphics.SetPixelOffsetMode(PixelOffsetModeHalf);
	OnTransform(graphics);
	Pen pen(Color(255 * stroke_opacity.getDouble(), stroke.getColor().GetR(), stroke.getColor().GetG(), stroke.getColor().GetB()), stroke_width.getDouble());
	SolidBrush brush(Color(255 * fill_opacity.getDouble(), fill.getColor().GetR(), fill.getColor().GetG(), fill.getColor().GetB()));
	if (!fill.getNone())
		graphics.FillEllipse(&brush, (int)(cx.getDouble() - r.getDouble()), (int)(cy.getDouble() - r.getDouble()), (int)(2 * r.getDouble()), (int)(2 * r.getDouble()));
	if (!stroke.getNone())
		graphics.DrawEllipse(&pen, (int)(cx.getDouble() - r.getDouble()), (int)(cy.getDouble() - r.getDouble()), (int)(2 * r.getDouble()), (int)(2 * r.getDouble()));
}

VOID _Ellipse::OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	graphics.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
	graphics.SetPixelOffsetMode(PixelOffsetModeHalf);
	OnTransform(graphics);
	Pen pen(Color(255 * stroke_opacity.getDouble(), stroke.getColor().GetR(), stroke.getColor().GetG(), stroke.getColor().GetB()), stroke_width.getDouble());
	SolidBrush brush(Color(255 * fill_opacity.getDouble(), fill.getColor().GetR(), fill.getColor().GetG(), fill.getColor().GetB()));
	if (!fill.getNone())
		graphics.FillEllipse(&brush, (int)(cx.getDouble() - rx.getDouble()), (int)(cy.getDouble() - ry.getDouble()), (int)(2 * rx.getDouble()), (int)(2 * ry.getDouble()));
	if (!stroke.getNone())
		graphics.DrawEllipse(&pen, (int)(cx.getDouble() - rx.getDouble()), (int)(cy.getDouble() - ry.getDouble()), (int)(2 * rx.getDouble()), (int)(2 * ry.getDouble()));
}

VOID _Polyline::OnPaint(HDC hdc)
{
	vector<PointF> tmp = points.getPoint();
	int size = tmp.size();
	Graphics graphics(hdc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	graphics.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
	graphics.SetPixelOffsetMode(PixelOffsetModeHalf);
	OnTransform(graphics);
	Pen pen(Color(255 * stroke_opacity.getDouble(), stroke.getColor().GetR(), stroke.getColor().GetG(), stroke.getColor().GetB()), stroke_width.getDouble());
	SolidBrush brush(Color(255 * fill_opacity.getDouble(), fill.getColor().GetR(), fill.getColor().GetG(), fill.getColor().GetB()));
	if (!fill.getNone())
		graphics.FillPolygon(&brush, &tmp[0], size);
	if (!stroke.getNone())
		graphics.DrawLines(&pen, &tmp[0], size);
}

VOID _Polygon::OnPaint(HDC hdc)
{
	vector<PointF> tmp = points.getPoint();
	int size = tmp.size();
	Graphics graphics(hdc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	graphics.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
	graphics.SetPixelOffsetMode(PixelOffsetModeHalf);
	OnTransform(graphics);
	Pen pen(Color(255 * stroke_opacity.getDouble(), stroke.getColor().GetR(), stroke.getColor().GetG(), stroke.getColor().GetB()), stroke_width.getDouble());
	SolidBrush brush(Color(255 * fill_opacity.getDouble(), fill.getColor().GetR(), fill.getColor().GetG(), fill.getColor().GetB()));
	if (!fill.getNone())
		graphics.FillPolygon(&brush, &tmp[0], size);
	if (!stroke.getNone())
		graphics.DrawPolygon(&pen, &tmp[0], size);
}

VOID _Text::OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	graphics.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
	graphics.SetPixelOffsetMode(PixelOffsetModeHalf);
	OnTransform(graphics);
	Pen pen(Color(255 * stroke_opacity.getDouble(), stroke.getColor().GetR(), stroke.getColor().GetG(), stroke.getColor().GetB()), stroke_width.getDouble());
	SolidBrush brush(Color(255 * fill_opacity.getDouble(), fill.getColor().GetR(), fill.getColor().GetG(), fill.getColor().GetB()));
	string myString = text.getString();
	wstring wide_string = wstring(myString.begin(), myString.end());
	const wchar_t* myText = wide_string.c_str();
	FontFamily fontfamily(L"Times new roman");
	Font font(&fontfamily, font_size.getDouble(), FontStyleRegular, UnitPixel);
	GraphicsPath path;
	StringFormat strformat(0, 0);
	path.AddString(myText, wcslen(myText), &fontfamily, FontStyleRegular, font_size.getDouble(), PointF(x.getDouble(), y.getDouble() - font_size.getDouble()), &strformat);
	if (!fill.getNone())
		graphics.FillPath(&brush, &path);
	if (!stroke.getNone())
		graphics.DrawPath(&pen, &path);
	//if (!fill.getNone())
		//graphics.DrawString(myText, wcslen(myText), &font, PointF(x.getDouble(), y.getDouble() - font_size.getDouble()), &brush);
}

VOID _Group::OnPaint(HDC hdc)
{
	int size = multiShape.size();
	for (int i = 0; i < size; i++)
		multiShape[i]->OnPaint(hdc);
}

VOID _Path::OnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);
	graphics.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
	graphics.SetPixelOffsetMode(PixelOffsetModeHalf);
	OnTransform(graphics);
	Pen pen(Color(255 * stroke_opacity.getDouble(), stroke.getColor().GetR(), stroke.getColor().GetG(), stroke.getColor().GetB()), stroke_width.getDouble());
	SolidBrush brush(Color(255 * fill_opacity.getDouble(), fill.getColor().GetR(), fill.getColor().GetG(), fill.getColor().GetB()));
	vector<pair<string, vector<float>>> f;
	f = d.getListCommand();
	PointF startPoint(0, 0), MPoint(0, 0);
	GraphicsPath path;
	int size = f.size(), sizeCommandName = commandName.size();
	for (int i = 0; i < size; i++)
		for (int j = 0; j < sizeCommandName; j++)
			if (commandName[j] == f[i].first)
			{
				switch (j)
				{
				case 0:
					if (!fill.getNone())
						graphics.FillPath(&brush, &path);
					if (!stroke.getNone())
						graphics.DrawPath(&pen, &path);
					path.Reset();
					path.SetFillMode(FillModeWinding);
					startPoint = PointF(f[i].second[0], f[i].second[1]);
					MPoint = PointF(f[i].second[0], f[i].second[1]);
					break;
				case 1:
					path.AddLine(startPoint, PointF(f[i].second[0], f[i].second[1]));
					startPoint = PointF(f[i].second[0], f[i].second[1]);
					break;
				case 2:
					path.AddLine(startPoint, PointF(startPoint.X + f[i].second[0], startPoint.Y));
					startPoint = PointF(startPoint.X + f[i].second[0], startPoint.Y);
					break;
				case 3:
					path.AddLine(startPoint, PointF(startPoint.X, startPoint.Y + f[i].second[0]));
					startPoint = PointF(startPoint.X, startPoint.Y + f[i].second[0]);
					break;
				case 4:
					path.AddBezier(startPoint, PointF(f[i].second[0], f[i].second[1]), PointF(f[i].second[2], f[i].second[3]), PointF(f[i].second[4], f[i].second[5]));
					startPoint = PointF(f[i].second[4], f[i].second[5]);
					break;
				case 5:
					path.AddLine(startPoint, MPoint);
					startPoint = MPoint;
					break;
				}
				break;
			}
	if (!fill.getNone())
		graphics.FillPath(&brush, &path);
	if (!stroke.getNone())
		graphics.DrawPath(&pen, &path);
}

//SET ATTRIBUTE

void Shape::setAttribute(string attr_name, string attr_value)
{
	int size = attr.size();
	for (int i = 0; i < size; i++)
		if (attr_name == attr[i]->getName())
		{
			attr[i]->setValue(attr_value);
			return;
		}
}

void ListOfShape::inputFromSVG()
{
	vector<pair<string, string>> myVec;
	int size, k = 0;
	string text;
	xml_document<> doc;
	xml_node<>* root_node;
	ifstream theFile("test/input.svg");
	if (!theFile)
		throw runtime_error("Could not open file!");
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);
	root_node = doc.first_node("svg");
	for (xml_node<> * node = root_node->first_node(); node; node = node->next_sibling())
	{
		size = shapeName.size();
		for (int i = 0; i < size; i++)
			if (shapeName[i] == node->name())
			{
				switch (i)
				{
				case 0: list.push_back(new _Line); break;
				case 1: list.push_back(new _Rect); break;
				case 2: list.push_back(new _Circle); break;
				case 3: list.push_back(new _Ellipse); break;
				case 4: list.push_back(new _Polyline); break;
				case 5: list.push_back(new _Polygon); break;
				case 6: list.push_back(new _Text); break;
				case 7: list.push_back(new _Group); break;
				case 8: list.push_back(new _Path); break;
				}
				list[k]->init();
				break;
			}
		if (node->name() == string("text"))
			list[k]->setAttribute(node->name(), node->value());
		while (node->first_attribute())
		{
			if (node->name() == string("g"))
				myVec.push_back(make_pair(node->first_attribute()->name(), node->first_attribute()->value()));
			list[k]->setAttribute(node->first_attribute()->name(), node->first_attribute()->value());
			node->remove_first_attribute();
		}
		list[k]->getAllAttribute();
		if (node->name() == string("g"))
		{
			list[k]->input(node, myVec);
			myVec.clear();
		}
		k++;
	}
}

void ListOfShape::draw(HDC hdc)
{
	int size = list.size();
	for (int i = 0; i < size; i++)
		list[i]->OnPaint(hdc);
}