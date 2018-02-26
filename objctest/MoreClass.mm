

#import "MoreClass.h"
#import "SomeClass.h"


@implementation MoreClass

- (void) doSomething {
	SomeClass* someClass = new SomeClass("gear");
	someClass->print();
	delete someClass;
}

@end
