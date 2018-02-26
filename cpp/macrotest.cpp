
#include <iostream>
#include <string>

typedef struct {
	int a;
	bool b;
	long j;
} jvalue;

#define MAKE_JVALUE(letter, value) \
	jvalue j; \
	j.letter = value; \
	return j;

jvalue makeValue(int v)
{
	MAKE_JVALUE(a, v)
}

jvalue makeValue(bool v)
{
	MAKE_JVALUE(b, v)
}

jvalue makeValue(long v)
{
	MAKE_JVALUE(j, v);
}

int main(int argc, char** argv)
{
	jvalue j = makeValue(4);
	printf("int: %i\n", j.a);
	j = makeValue(10L);
	printf("long: %ld\n", j.j);
	j = makeValue(true);
	printf("bool: %s\n", j.b ? "true" : "false");
	return 0;
}
