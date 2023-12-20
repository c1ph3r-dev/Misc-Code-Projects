#include "logistics.h"

Logistic::Logistic(int ID, std::string Name, std::string Desc, USD Cost)
	:log_item_id(ID), item_info(Desc), item_name(Name), cost_ttd(Cost.toTTD())
{
}
