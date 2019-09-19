class IEnsamble
{
	public:
		virtual void SetSize() = 0;
		virtual ~IEnsamble(){}
};

class Canonical : public IEnsamble
{
	public:
		virtual void SetSize()
		{
	
		}
};

class ParityGrandCanonical : public IEnsamble
{
	public:
		void SetSize()
		{
	
		}
};

class CompleteCanonical : public IEnsamble
{
	public:
		void SetSize()
		{
	
		}
};


