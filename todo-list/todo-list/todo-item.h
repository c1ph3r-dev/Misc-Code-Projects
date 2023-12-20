#pragma once

#include <string>

#ifndef TODO_ITEM_H_
#define TODO_ITEM_H_

class TodoItem
{
private:
	int id;
	std::string desc;
	bool bCompleted;

	static int id_iterator;
public:
	TodoItem() : id(0), desc(""), bCompleted(false) {};
	virtual ~TodoItem() = default;

	void create(const std::string& new_description) noexcept;

	[[nodiscard]] inline int GetID() const noexcept { return id; }
	[[nodiscard]] inline std::string GetDescription() const noexcept { return desc; }
	[[nodiscard]] inline bool isCompleted() const noexcept { return bCompleted; }

	inline void SetCompleted(bool val) noexcept { bCompleted = val; }
};

#endif // !TODO_ITEM_H_
