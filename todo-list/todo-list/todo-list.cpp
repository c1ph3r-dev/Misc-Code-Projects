// todo-list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>

#include "todo-item.h"

void MarkItemAsCompleted(std::list<TodoItem>& todo_list)
{
    std::cout << "Enter id of Todo item to mark as completed: ";
    int input_id;

    std::cin >> input_id;

    for (auto& item : todo_list)
    {
        if (item.GetID() == input_id)
        {
            item.SetCompleted(true);
            break;
        }
    }
}

TodoItem AddItem()
{
    std::string input_desc;
    std::cout << "Add a new description: ";
    std::cin.clear();
    std::cin.ignore();
    std::getline(std::cin, input_desc);

    TodoItem item;
    item.create(input_desc);
    return item;
}

int main()
{
    std::string version = "v.0.2.0";
    std::list<TodoItem> todoItems;

    todoItems.clear();


    bool loop{ true };
    while (loop == true)
    {
        system("cls");
        char input_option{};
        std::cout << "Todo List Maker - " << version << '\n';
        std::cout << "\n\n";

        for (auto& item : todoItems)
        {
            std::string completed = item.isCompleted() ? "done" : "not done";

            std::cout << item.GetID() << " | " << item.GetDescription() << " | " << completed << '\n';
        }

        if (todoItems.empty())
            std::cout << "Add your first todo!\n";

        std::cout << '\n';
        std::cout << "[a]dd a new Todo\n";
        std::cout << "[c]omplete a Todo\n";
        std::cout << "[q]uit\n";

        std::cout << "choice: ";
        std::cin >> input_option;

        switch (input_option)
        {
        default:
            break;
        case 'q':
            std::cout << "Have a great day now!" << std::endl;
            loop = false;
            break;
        case 'a':
            todoItems.push_back(AddItem());
            break;
        case 'c':
            MarkItemAsCompleted(todoItems);
            break;
        }
    }
}

