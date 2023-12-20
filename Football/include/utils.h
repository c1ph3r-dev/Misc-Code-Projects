#ifndef JRAMPERSAD_FOOTBALL_UTILS_H
#define JRAMPERSAD_FOOTBALL_UTILS_H

#include <vector>

namespace JRAMPERSAD
{
#define GETTER_FUNC(type, name) \
inline type Get##name() const { return name; }
#define SETTER_FUNC(type, name) \
inline void Set##name(type New##name) { name = New##name; }

#define CLASS_ACCESSORS(type, name) \
GETTER_FUNC(type, name) \
SETTER_FUNC(type, name)

	enum class EPosition
	{
	    EP_GK = 0,
	    EP_RWB,
	    EP_RB,
	    EP_CB,
	    EP_LB,
	    EP_LWB,
	    EP_CDM,
	    EP_RM,
	    EP_CM,
	    EP_LM,
	    EP_CAM,
	    EP_CF,
	    EP_RW,
	    EP_LW,
	    EP_ST
	};

	template <typename T>
	void RemoveItemFromVector(std::vector<T*>& vec, const T& item)
	{
		size_t i{0};
		for (auto& val : vec)
		{
			if(val == &item)
				break;
			i++;
		}

		vec.erase(vec.begin() + i);
	}
}

#endif // JRAMPERSAD_FOOTBALL_UTILS_H