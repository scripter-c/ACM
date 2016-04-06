#include<iostream>
#include<string>

using namespace std;

class angl
{
public:
	void operator +(double c) { angle += c; if (angle > 360)angle -= 360; if (angle < 0)angle = angle + 360;  }
	void operator -(double c) { angle -= c; if (angle > 360)angle -= 360; if (angle < 0)angle = angle + 360;  }
	void operator *(double c) { angle *= c; if (angle > 360)angle -= 360; if (angle < 0)angle = angle + 360;  }
	void operator /(double c) { angle /= c; if (angle > 360)angle -= 360; if (angle < 0)angle = angle + 360;  }
	//void operator =(double c) { angle = c; if (angle > 360)angle -= 360; if(angle < 0)angle = angle + 360;}
	friend angl operator -(double c, angl angle) { angle.angle = angle.angle - c; return angle; }
	friend void operator << (ostream& os, angl angle) { os << angle; }
private:
	double angle;
};
 

class line
{
public:
	line(int length);
	line() { angle; }
	void output();
	void opposite_path();
	void set_angle(const double pass) { }
	line operator= (line line);
	friend line operator +(int l, line line);
	friend line operator -(int l, line line);
	friend line operator *(int l, line line);
	friend line operator /(int l, line line);
	angl angle;
private:
	double x;
	double y;
	double length;
};

line operator+(int l, line line)
{
	int length = line.length;
	line.length += l;
	line.x = line.x*line.length / length;
	line.y = line.y*line.length / length;
	return line;
}
line operator-(int l, line line)
{
	int length = line.length;
	line.length -= l;
	line.x = line.x*line.length / length;
	line.y = line.y*line.length / length;
	return line;
}
line operator*(int l, line line)
{
	int length = line.length;
	line.length *= l;
	line.x = line.x*line.length / length;
	line.y = line.y*line.length / length;
	return line;
}
line operator/(int l, line line)
{
	int length = line.length;
	line.length /= l;
	line.x = line.x*line.length / length;
	line.y = line.y*line.length / length;
	return line;
}

void line::opposite_path()
{
	x=-x;
	y = -y;
}

line line::operator=(line line)
{
	x = line.x;
	y = line.y;
	angle = line.angle;
	length = line.length;
	return line;
}

void line::output()
{
	cout << "length:"<<length<<endl;
	cout << "x:" << x << endl;
	cout << "y" << y << endl;
	cout << "angle" << angle ;
}

line::line(int lengths)
{
	length = lengths;
	for (double i = 0.0001; ; i += 0.0001)
	{
		if (i*i * 2 >= lengths*lengths)
		{
			x = i;
			y = i;
			break;
		}
	}
}
