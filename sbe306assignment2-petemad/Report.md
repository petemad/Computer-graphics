# Assignment 2 report

## Implementation
* I started by camera part of the task and it was pretty easy and expected in moving forward and bacward but in the part of rotating it, I think it is more compicated.

* Frist I made the rotation based on the eye place only using lookat opengl function.

* It was not working like the shown in the assignment page but it still rotating with some constrains about the angle as it has limit.

* I found help from my classmate Ahmed Shaaban, as he told me to use the implemented rotatePoint function.

* The most thing he helped me with was this line of code and I still do not know why I should write double in this way in function parameters.
```c 
	rotatePoint(ax,(double)-5/180*3.14,eye);
```

* the second part of implementing the whole body was not easy in the begining but quickly it repeats itself with diffrent parameters nothing less neither more.

* I googled for some websites that helped me with the implementation. mentioned below.


## Links I have visited during solving the task

https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/gluLookAt.xml

https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/gluSphere.xml

https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/gluNewQuadric.xml

## Problem faced
### problem 1
```c
int limit (int angle, int max , char sign){
	if (sign == '+'){
		if (angle+5 == 0) {angle = (angle + 5) % max; glutPostRedisplay();}
		if ( (angle + 5) % max == 0){ return 0;}
		angle = (angle + 5) % max ;
		glutPostRedisplay();
		return 0;}
	else if (sign == '-'){
		if (angle-5 == 0) {angle = (angle - 5) % max; glutPostRedisplay();}
		if ( (angle - 5) % -max == 0){ return 0;}
		angle = (angle - 5) % max ;
		glutPostRedisplay();
		return 0;}
	return 0 ;
}
```

limit function implemented to replace the limits and conditions in the switch case statement
```c
    case('x')
		if (shoulder2+5 == 0) {shoulder2 = (shoulder2 + 5) % 100; glutPostRedisplay();}
		if ( (shoulder2 + 5) % 100 == 0){ break;}
		shoulder2 = (shoulder2 + 5) % 100 ;
		glutPostRedisplay();
	break;
```
 unfortunatly it was working in only one direction although changing the keyboard input letter (key). 

I have no idea what is going on with this.

### problem 2

It is not a real problem but I am just wondering why function normalise and crossProduct are implemented for also, what do rhip2 and lhip2  variables created for ? 

I did not found any reason to be created.

### concern 

I foud that, if only one ``` glMatrixPush(); ``` was written with no opposite pop function it will make a huge changes in the object drawn, although it is only push which does not change the current matrix, I also do not why this acts like this. 

# Finally 
## Many thanks because of your efforts with us.