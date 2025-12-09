#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point() { x = 0; y = 0; }
	Point(const int x, const int y) : x(x), y(y) {}
	void Print();
	void PrintCircular(bool ishead);
	void Clear();
	void ChangePosition(const int x, const int y);
	int X() { return this->x; }
	int Y() { return this->y; }

	void SetX(const int x) { this->x = x; }
	void SetY(const int y) { this->y = y; }

	int AddX(const int x) { this->x += x;  return this->x; }
	int AddY(const int y) { this->y += y; return this->y; }

	bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
	int GetX() { return this->x; }
	int GetY() { return this->y; }
private:
	int x, y;
};
#endif // POINT_H