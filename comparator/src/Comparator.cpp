#include "../inc/Comparator.h"

void Comparator::Comparator_Proc(void)
{
	( InA.read() >  InB.read() ) ?  GT.write( true  ) :
	( InA.read() == InB.read() ) ?  GT.write( false ) :
				        GT.write( false );

	( InA.read() >  InB.read() ) ? EQ.write( false ) :
	( InA.read() == InB.read() ) ? EQ.write( true  ) :
				       EQ.write( false );
	

}
