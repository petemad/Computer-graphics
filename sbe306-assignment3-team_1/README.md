## Compile 

# sbe306-assignment3-team_1
## Team members:
- Sahar Hamdy
- Peter Emad
- Sohila Mohamed
- Moahmed Yousry

### implementation:

- using the full body which was implemented last assignment 
- we made the body animated by change the angles of its limbs with timer
- created the objects which we need for our scene
- apply the texture mapping by using image.BMP to creat the floor of our scene

### problems we faced:
- some of us wasn't have ubuntu which took some time to start working at task
- we can't understand every line in the code which was implemented at the tutorial
- at the part of animation, sometimes the speed of movement increases suddenly and we have no idea why!!
- how to make the floor image dosen't show as repeated squars

##### the three animations can run using keys "1" , "2" , "3"

### sample of code:

#### Two animations
```c
	// animation 1
	void ta4gee3 (void){
		goTimer(0) ;
	}

	// animation 2
	void tamareen_elsba7(void){
		goTimer(2) ;	
		goTimer(3) ;
	}


```

#### Interacting with object
The robot pulls a wire to control a cone in the scene. 
```c
	// animation 3 interacting with object
	void wirePull(void){
		goTimer(6) ;
		goTimer(8) ;
	}
```

##### The function goTimer 
```c
void goTimer (int value ){
	if (value == 0)
    {
        shoulder = (shoulder + 1) ;
		shoulder2 = (shoulder2 + 1) ;
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 0);
		if ((shoulder2 + 1) > 100) {
			glutTimerFunc(0, goTimer, 1);
		}
    }
    else if (value == 1)
    {
        shoulder = (shoulder - 1);
		shoulder2 = (shoulder2 - 1);
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 1);
		if ((shoulder2 - 1) < -100 ) {
			glutTimerFunc(0, goTimer, 0);
		}
    }
	else if (value == 2)
    {
        lhip = (lhip - 1);
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 2);
		if ((lhip - 1) < -100 ) {
			glutTimerFunc(0, goTimer, 5);
		}
    }
	else if (value == 3)
    {
        lknee = (lknee - 1);
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 3);
		if ((lknee - 1) < -120 ) {
			glutTimerFunc(0, goTimer, 4);
		}
    }
	else if (value == 4)
    {
        lknee = (lknee + 1);
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 4);
		if ((lknee + 1) > 0 ) {
			glutTimerFunc(0, goTimer, 3);
		}
    }
	else if (value == 5)
    {
        lhip = (lhip + 1);
        glutPostRedisplay();
        glutTimerFunc(10, goTimer, 5);
		if ((lhip + 1) > 100 ) {
			glutTimerFunc(0,goTimer,2);
		}
    }
}
```
#### texture mapping
```c
    GLuint loadTexture(Image *image)
    {
	    GLuint textureId;
	    glGenTextures(1, &textureId);	
	    glBindTexture(GL_TEXTURE_2D, textureId); 
	    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,image->width, image->height,            0,GL_RGB,GL_UNSIGNED_BYTE,image->pixels);	
	    return textureId;	
    }

* Select different objects rotating on the table


## Objects 

* Our objects are ( Earth - Rocket - Moon - Saturn ) 

``` C
    case 's':
		name = "data/earth.obj";
		AngleX = 0;
		break;
	case 'd':
		name = "data/saturn.obj";
		AngleX = 120;
		break;
	case 'f':
		name = "data/moon.obj";
		AngleX = -90;
		break;
	case 'j':
		name = "data/10475_Rocket_Ship_v1_L3.obj";
		AngleX = -90;
		break;
``` 
* And we also have other Objects ( Telescope - Rover ) _______ this Objects the character will be able to interact with it to see Other Objects ( Earth - Moon - ... )

``` C
	pmodelll = glmReadOBJ("data/rover.obj");
```

``` C
	pmodelll = glmReadOBJ("data/telescope.obj");
```

