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
const add_todo_button = document.getElementById("add-todo-button");
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

/*
    Add an event listener to the add_todo_button.
*/
add_todo_button.addEventListener("click", function() {
    /*
        Get the value entered in the input field.
    */
    const new_todo_text = todo_input.value;
    /*
        Check if the input field is empty.
    */
    if (new_todo_text.trim() === "") {
        alert("Please enter a valid task!");
        return;
    }
    /*
        Generate a timestamp for the new todo/task.
    */
    const timestamp = get_formatted_timestamp();
    /*
        Create a new list item element for the new task.
    */
    const new_todo_item = document.createElement("LI");
    new_todo_item.classList.add("todo-item");
    new_todo_item.textContent = new_todo_text;
    const timestamp_element = document.createElement("span");
    timestamp_element.classList.add("timestamp");
    timestamp_element.textContent = timestamp;
    new_todo_item.appendChild(timestamp_element);
    /*
        Add the new todo list item to the todo-list-container and update progress bar.
    */
    todo_list_container.appendChild(new_todo_item);
    update_progress_bar();
    /*
        Clear the todo input field for the next task.
    */
    todo_input.value = "";
});