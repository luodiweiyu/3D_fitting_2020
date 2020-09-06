#include"Line.h"
Line::Line(Surface& s1_, Surface& s2_)
{
	upd(s1_, s2_);
}
Line::Line(Point& pt1, Point& pt2)
{
	upd(pt1, pt2);
}

void Line::upd(Surface& s1_, Surface& s2_)
{
	//��������ƽ���ʼ��ֱ�ߣ�
	//���ܴ�����ƽ��ƽ�л���ϵ��Ϊ����������Ҫ���⿼�ǣ�
	if (s2_.a() * s2_.b() * s2_.c() != 0)
	{
		if (s1_.a() / s2_.a() == s2_.b() / s2_.b() && s1_.a() / s2_.a() == s2_.c() / s2_.c())
			throw "��ֱ��ƽ�У��޷�����ֱ�ߣ�";
		else
			s1 = s1_, s2 = s2_;
	}
	else if (s2_.a() == 0)
	{
		if (s1_.a() != 0)
			s1 = s1_, s2 = s2_;
		else if (s2_.b() == 0)
		{
			if (s1_.b() == 0)
				throw "��ֱ��ƽ�У��޷�����ֱ�ߣ�";
			else
				s1 = s1_, s2 = s2_;
		}
		else if (s2_.c() == 0)
		{
			if (s1_.c() == 0)
				throw "��ֱ��ƽ�У��޷�����ֱ�ߣ�";
			else
				s1 = s1_, s2 = s2_;
		}
		else if (s1_.b() / s2_.b() == s2_.c() / s2_.c())
			throw "��ֱ��ƽ�У��޷�����ֱ�ߣ�";
		else
			s1 = s1_, s2 = s2_;
	}
	else if (s2_.b() == 0)
	{
		if (s1_.b() != 0)
			s1 = s1_, s2 = s2_;
		else if (s2_.c() == 0)
		{
			if (s1_.c() == 0)
				throw "��ֱ��ƽ�У��޷�����ֱ�ߣ�";
			else
				s1 = s1_, s2 = s2_;
		}
		else if (s1_.a() / s2_.a() == s2_.c() / s2_.c())
			throw "��ֱ��ƽ�У��޷�����ֱ�ߣ�";
		else
			s1 = s1_, s2 = s2_;
	}
	else //s2_.c()==0
	{
		if (s1_.c() != 0)
			s1 = s1_, s2 = s2_;
		else if (s1_.a() / s2_.a() == s2_.b() / s2_.b())
			throw "��ֱ��ƽ�У��޷�����ֱ�ߣ�";
		else
			s1 = s1_, s2 = s2_;
	}

}
void Line::upd(Point& pt1, Point& pt2)
{
	//������������һ��ֱ�ߣ�
	//���ܴ��������ĳ��������ȵ������
	double vect_x = pt1.x() - pt2.x();
	double vect_y = pt1.y() - pt2.y();
	double vect_z = pt1.z() - pt2.z();
	if (abs(vect_x) == 0 && abs(vect_y) == 0)
	{
		s1.updateCof(1, 0, 0, -pt1.x());
		s2.updateCof(0, 1, 0, -pt1.y());
	}
	else if (abs(vect_x) == 0 && abs(vect_z) == 0)
	{
		s1.updateCof(1, 0, 0, -pt1.x());
		s2.updateCof(0, 0, 1, -pt1.z());
	}
	else if (abs(vect_y) == 0 && abs(vect_z) == 0)
	{
		s1.updateCof(0, 1, 0, -pt1.y());
		s2.updateCof(0, 0, 1, -pt1.z());
	}
	else
	{
		s1.updateCof(vect_y, vect_x, 0, -vect_y * pt2.x() + vect_x * pt2.y());
		s2.updateCof(vect_z, 0, -vect_x, -vect_z * pt2.x() + vect_x * pt2.z());
	}

}
//��ʽ���û��๹�캯��
zoneLine::zoneLine(Point& basept, Point& meshpt)
{
	upd(basept, meshpt);
}
void zoneLine::upd(Point& basept, Point& meshpt)
{
	Line::upd(basept, meshpt);
	basePt = basept;
	basePt = meshpt;
}