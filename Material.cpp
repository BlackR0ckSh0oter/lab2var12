#include<iostream>
#include<locale>
#include "Material.h"

using namespace std;

/* ŒÕ—“–” “Œ–€*/

material::material() : element(0.0) {}
material::material(float value)
{
	element = value;
}
material::~material() {}
material::material(const material& material_copy)
{
	this->element = material_copy.element;
}

/*Ã≈“Œƒ€*/

material operator + (const material & l, const material & r) { return material(l.element + r.element); }
material operator * (const material& l, const material& r) { return material(l.element * r.element); }

material operator - (const material& r, float a) { return material(r.element - a); }
material operator - (float a, const material& r) { return material(a - r.element); }

material operator / (const material& r, float a) { return material(r.element / a); }
material operator / (float a, const material& r) { return material(a / r.element); }

material& material::operator = (const material& r)
{
	if (this == &r) 
		return *this;
	element = r.element;
	return *this;
}

material& material::operator = (float a)
{
	element = a;
	return *this;
}

void material::set_element(float& value) { element = value; }
float material::get_element() const { return element; }

void material::out() { cout << element << endl; }
