#include "todo-item.h"

int TodoItem::id_iterator = 1;

void TodoItem::create(const std::string& new_description) noexcept
{
	id = id_iterator;
	desc = new_description;

	++id_iterator;
}
