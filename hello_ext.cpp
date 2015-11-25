#include <iostream>
#include <vector>
#include <boost/python.hpp>
using namespace boost::python;

class iCounter {
	private:
		std::vector<int> Positions;
		int size;
	public:
		iCounter(void);
		~iCounter(void);
		void addPosition(int pos);
		void printIdx(int idx);
		tuple maximumStretch(int islandLength);
};

iCounter::iCounter()
{
	size=0;
}

iCounter::~iCounter(void)
{
}

void iCounter::addPosition(int pos)
{
	Positions.push_back(pos);
	size=int(Positions.size());	
}

void iCounter::printIdx(int idx)
{
	if(Positions.size() < idx)
	{
		std::cout << "Invalid Index!\n";
		return;
	}
	
	std::cout << Positions[idx] << "\n";
	return;
}

tuple iCounter::maximumStretch(int islandLength)
{
	if(Positions.size()==0)
		return make_tuple(-1,-1);
	int tmp_max_stretch_start = 0;
	int tmp_max_stretch_len=0;
	int current_stretch_start = tmp_max_stretch_start;
	int current_stretch_len = 0;
	int i=0;
	
	for(int i = 0; i < Positions.size(); i++)
	{
		while(Positions[i+1]-Positions[i]+1 < islandLength)
		{					
			current_stretch_len++;
			i++;
		}
		if(current_stretch_len > tmp_max_stretch_len)
		{
			tmp_max_stretch_start = current_stretch_start;
			tmp_max_stretch_len=current_stretch_len;				
		}

		current_stretch_len=0;
	}
	return make_tuple(Positions[tmp_max_stretch_start], Positions[tmp_max_stretch_start + tmp_max_stretch_len]);
}


char const* greet()
{
       return "hello, world";
}
 

  
BOOST_PYTHON_MODULE(hello_ext)
{
      //using namespace boost::python;
          //def("greet", greet);
		  
		  class_<iCounter>("PyiCounter")
		  .def("addPosition", &iCounter::addPosition)
		  .def("maximumStretch", &iCounter::maximumStretch)
		  .def("printIdx", &iCounter::printIdx)
		  ;
}
