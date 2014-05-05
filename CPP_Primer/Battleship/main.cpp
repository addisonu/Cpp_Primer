
#include "PointCollection.h"
#include "Ship.h"
#include <iostream>

using namespace std;

 void test_pointc();

int main()
{
	test_pointc();

	point origin(0,0);
	point origin2(6,7);
	point a_pnt = origin2;
	int length = 3;
	
	Ship ship1(origin, HORIZONTAL, length);
	Ship ship2(origin2, VERTICAL, length);
	Ship ship3 = ship2;
	for(int n = 0; n < 3; n++){
		ship2.shotFiredAtPoint(a_pnt);	
		a_pnt.setY(a_pnt.getY() + 1);
		
		std::cout << ship2.containsPoint(a_pnt) << std::endl;
	}
	std::cout << "Do ship1 and ship2 collide? : " << ship1.collidesWith(ship2) << std::endl;
	std::cout << "Do ship3 and ship2 collide? : " << ship3.collidesWith(ship2) << std::endl;

	std::cout << "Has a shot been fired at the origin of ship2? : " << ship2.isHitAtPoint(origin2) << std::endl;
	std::cout << "Is ship2 sunk? : " << ship2.isSunk() << std::endl;
	std::cout << "How many times has ship2 been hit? : " << ship2.hitCount() << std::endl;
}
void test_pointc()
{
	point add_pnt(7, 7);
	point &r_pnt = add_pnt;

	PointCollection t_pnt;
	t_pnt << add_pnt;

	std::cout << "Does it contain (7,7)? :" << t_pnt.contains(r_pnt) << std::endl;
}

void testContains(const Ship &s, int x, int y, bool desiredResult, int num) {
	point p(x, y);

	if (s.containsPoint(p) != desiredResult) 
		cout << "Problem with contains test " << num << endl;
}

void testThreeArgConstructorAndContainsPoint() {
	point origin(0, 0);
	Ship s1(origin, HORIZONTAL, 3);
	Ship s2(origin, VERTICAL, 4);

	testContains(s1, 0, 0, true, 0);
	testContains(s1, 1, 0, true, 1);
	testContains(s1, 2, 0, true, 2);
	testContains(s1, 3, 0, false, 3);
	testContains(s2, 0, 0, true, 4);
	testContains(s2, 0, 1, true, 5);
	testContains(s2, 0, 2, true, 6);
	testContains(s2, 0, 3, true, 7);
	testContains(s2, 0, 4, false, 8);
	testContains(s2, 1, 1, false, 9);
	testContains(s1, -1, 0, false, 10);
	testContains(s2, 0, -1, false, 11);

}

void testCopyAssignmentAndConstructor() {
	point origin(0, 0);
	Ship s1(origin, HORIZONTAL, 3);
	Ship s2(s1);

	testContains(s2, 0, 0, true, 20);
	testContains(s2, 1, 0, true, 21);
	testContains(s2, 2, 0, true, 22);
	testContains(s2, 3, 0, false, 23);
}

void testCollidesWith() {
	point origin(0, 0);

	Ship s1(origin, HORIZONTAL, 3);
	Ship collisionShip(origin, VERTICAL, 4);

	if (!s1.collidesWith(collisionShip)) 
		cout << "problem with collides with 1" << endl;

	point oneOne(1, 1);
	Ship noCollisionShip(oneOne, HORIZONTAL, 3);

	if (s1.collidesWith(noCollisionShip))
		cout << "problem with collides with 2" << endl;
}

void testHitMethods() {
	point origin(0, 0);
	Ship s1(origin, HORIZONTAL, 3);

	point p = origin;

	s1.shotFiredAtPoint(p);
	if (s1.hitCount() != 1) cout << "Problem: hitCount 1" << endl;	
	if (s1.isSunk()) cout << "Problem with isSunk 1" << endl;

	// Further testing required
}
/*
int main() {
	//testHitMethods();
	//testCollidesWith();
	//testCopyAssignmentAndConstructor();
	//testThreeArgConstructorAndContainsPoint();


}
*/
