/* Author: Ishan Misra
   Please use this file for non-commerical purposes only.
   Also cite the original author if you happen to use this file.
*/   

#include <stdio.h>
#include <stdlib.h>

/* This struct is given by the manufacturer */
class gun
{
	private:
	int num_bullets;

	//the cylinder to hold the bullets
	//cylinder[i]=1 indicates ith position of cylinder has a bullet
	int *cylinder;

	//the position of the cylinder
	//indicates which bullet is to be fired next
	int cylinder_position;

	public:
	//creates a new gun and fills it with bullets
	gun()
	{
		//now set the variables in the struct
		num_bullets = 6; //default

		//allocate memory to the cylinder
		cylinder = (int *)malloc(sizeof(int)*num_bullets);

		//now initialize cylinder position
		cylinder_position = 0;

		load_gun();
	}

	//creates a new gun with n bullets
	//n is automatically adjusted to be >=1
	gun(int n)
	{
		//sanity check
		(n <= 0 ) ? n=1 : n=n;

		//now set the variables in the struct
		num_bullets = n; //default

		//allocate memory to the cylinder
		cylinder = (int *)malloc(sizeof(int)*num_bullets);

		//now initialize cylinder position
		cylinder_position = 0;

		load_gun();
	}

	~gun()
	{
		free(cylinder);
	}

	//check if there is a bullet under trigger
	//return 1 if the bullet is present, 0 otherwise
	int is_bullet_present()
	{
		if(cylinder[cylinder_position]==1)
			return 1;
		return 0;
	}

	//fires a gun
	//returns 1 if successfully fired, 0 otherwise
	int fire_gun()
	{
		int fired = 0;
		if(is_bullet_present()==1) 
		{
			cylinder[cylinder_position] = 0;
			fired = 1;
		}
		cylinder_position = (++cylinder_position)%num_bullets;
		return fired;
	}

	//fires a gun n times.
	//n is automatically adjusted to be >=1
	//returns 1 if all fires were successful, 0 otherwise
	int fire_gun(int n)
	{
		int fired = 1;
		int i;

		//sanity checks
		n<=0 ? n=1 : n=n;

		for(i=0;i<n;i++)
		{
			fired = fired & fire_gun();
		}
		return fired;
	}

	//loads cylinder with bullets
	void load_gun()
	{
		int i;
		for (i=0;i<num_bullets;i++)
		{
			cylinder[i]=1; //fill in bullets
		}
	}

};

int main(int argc,char *argv[]) {

//	struct gun *g;
//	init_gun(&g);
	gun g(14);

	int i;
	for(i=0;i<12;i++)
		//printf("fire %d\n",fire_gun(g));
		printf("fire %d\n",g.fire_gun());


	//load_gun(g);
//	g.load_gun();

	printf("fireN %d\n",g.fire_gun(2));

	for(i=0;i<12;i++)
		printf("fire %d\n",g.fire_gun());
		//printf("fire %d\n",fire_gun(g));
	return 0;
}
