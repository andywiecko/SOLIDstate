#ifndef TERM_H
#define TERM_H

class ITerm
{
	public:
		virtual void FillElements() = 0;
		virtual ~ITerm(){}
};

#endif