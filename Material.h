#pragma once

class material
{
private:
	float element;

public:
	material();
	explicit material(float value);
	~material();
	material(const material& material_copy);

	friend material operator - (const material& r, float a);
	friend material operator - (float a, const material& r);

	friend material operator / (const material& r, float a);
	friend material operator / (float a, const material& r);
	
	material& operator = (float a);

	material& operator = (const material& r); 
	void set_element(float& value);
	float get_element() const;

	friend material operator + (const material & l, const material & r); 
	friend material operator * (const material& l, const material& r);
	void out();
};
