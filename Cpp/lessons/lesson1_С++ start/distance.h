#pragma once

struct Distance
{
	int Feet;
	float Inches;
};

Distance Read();
Distance Summ(Distance const& d1, Distance const& d2);
Distance Diff(Distance const& d1, Distance const& d2);
void Print(Distance const& d);