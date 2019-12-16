//File name: parser.h
//------------------------------------------------------------------------------------------------------------------------------------------
//Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//Creation Date: 12/11/2019
//Date of last modification: 12/12/2019
//------------------------------------------------------------------------------------------------------------------------------------------
//Parser for shape file

#pragma once

#ifndef PARSER_H
#define PARSER_H

#include <string>

using namespace std;

struct TokenType {
	string tag;
	string value;
};

enum Shapes {line, polyline, polygon, rectangle, square, ellipse, circle, text};
// can use Qt::GlobalColor enum
enum PenColors {white, black, red, green, blue, cyan, magenta, yellow, gray};
// can use Qt::PenStyle enum
enum PenStyle {NoPen, SolidLine, DashLine, DotLine, DashDotLine, DashDotDotLine};
// can use Qt::PenCapStyle
enum PenCapStyle {FlatCap, SquareCap, RoundCap};
// can use Qt::PenJoinStyle
enum PenJoinStyle {MiterJoin, BevelJoin, RoundJoin};
// can use Qt::BrushStyle
enum BrushStyle {SolidPattern, HorPattern, VerPattern, NoBrush};
//can use Qt::AlignmentFlag
enum TextAlignment {AlignLeft, AlignRight, AlignTop, AlignBottom, AlignCenter};
//can use QFont::Style
enum TextFontStyle {StyleNormal, StyleItalic, StyleOblique};
//can use QFont::Weight
enum TextFontWeight {Thin, Light, Normal, Bold};

const string ShapesStr[] = {"line", "polyline", "polygon", "rectangle",
						"square", "ellipse", "circle", "text"};
const string PenColorStr[] = {"white", "black", "red", "green", "blue", 
					   	"cyan", "magenta", "yellow", "gray"};
const string PenStyleStr[] = {"NoPen", "SolidLine", "DashLine", "DotLine",
						"DashDotLine", "DashDotDotLine"};
const string PenCapStyleStr[] = {"FlatCap", "SquareCap", "RoundCap"};
const string PenJoinStyleStr[] = {"MiterJoin", "BevelJoin", "RoundJoin"};
const string BrushStyleStr[] = {"SolidPattern", "HorPattern", "VerPattern", "NoBrush"};
const string TextAlignmentStr[] = {"AlignLeft", "AlignRight", "AlignTop", 
						"AlignBottom", "AlignCenter"};
const string TextFontStyleStr[] = {"StyleNormal", "StyleItalic", "StyleOblique"};
const string TextFontWeightStr[] = {"Thin", "Light", "Normal", "Bold"};

struct ShapeInfoType {
	int shapeID;
    Shapes shape;
    string shapeDimensions;
    PenColors penColor;
    int penWidth;
    PenStyle penStyle;
    PenCapStyle penCapStyle;
    PenJoinStyle penJoinStyle;
    PenColors brushColor;
    BrushStyle brushStyle;
    string text;
    PenColors textColor;
    TextAlignment textAlignment;
    int textPointSize;
    string textFontFamily;
    TextFontStyle textFontStyle;
    TextFontWeight textFontWeight;
};

// global constants

// function prototypes
string lowerCase(string s);
void loadShapeFile(string shapeFile);
int getShapeID(string line);
TokenType getToken(string line);

#endif