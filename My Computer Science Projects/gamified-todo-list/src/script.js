/*
    Get references to:
    - todo list container
    - todo input field
    - add todo button
    - clear all todos button
    - progress bar
    - progress percentage
*/
const todo_list_container = document.getElementById("todo-list-container");
const todo_input = document.getElementById("todo-input");
const add_button = document.getElementById("add-todo-button");
const clear_all_todos_button = document.getElementById("clear-all-todos-button");
const progress_bar = document.getElementById("progress-bar");
const progress_percentage = document.getElementById("progress-percentage");

/*
    function get_formatted_timestamp()
    - returns formatted string of current time
*/
function get_formatted_timestamp() {
    const date = new Date();
    const hours = date.getHours().toString().padStart(2, "0");
    const minutes = date.getMinutes().toString.padStart(2, "0");
    const seconds = date.getSeconds().toString().padStart(2, "0");
    return `${hours}:${minutes}:${seconds}`;
}