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
    function update_progress_bar()
    - updates/modifies progress bar width & percentage based on completion ratio.
*/
function update_progress_bar() {
    const number_completed_tasks = todo_list_container.querySelectorAll(".completed").length;
    const number_total_tasks = todo_list_container.querySelectorAll("LI").length;
    /*
        Check if there are any tasks...
    */
    if (number_total_tasks === 0) {
        /*
            Set progress to 0 and display default percentage.
        */
        const progress = 0;
        progress_percentage.textContent = `${progress.toFixed(1)}%`;
        if (progress >= 80) {
            progress_percentage.style.color = "#4caf50";
        } else {
            progress_percentage.style.color = "crimson";
        }
    } else {
        /*
            Calculate the progress percentage.
        */
        const progress = (number_completed_tasks / number_total_tasks) * 100;
        /*
            Update the progress bar width.
        */
        progress_bar.style.width = `${progress}`;
        /*
            Update the progress percentage text and styling.
        */
        progress_percentage.textContent = `${progress.toFixed(1)}%`;
        /*
            Update the color of the percentage text based on progress.
        */
        if (progress >= 80) {
            progress_percentage.style.color = "#4caf50";
        } else {
            progress_percentage.style.color = "crimson";
        }
    }
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

/*
    Add an event listener to the clear_all_todos_button.
*/
clear_all_todos_button.addEventListener("click", function() {
    /*
        Confirm with the user before clearing all tasks.
    */
    if (confirm("Are you sure you want to clear all tasks?")) {
        /*
            Remove all todo list items from the todo-list-container.
        */
        const todo_items = todo_list_container.querySelectorAll("LI");
        /*
            Loop through each list item and remove it.
        */
        for (let i = 0; i < todo_items.length; i++) {
            todo_list_container.removeChild(todo_items[i]);
        }
        /*
            Reset the progress bar & percentage with width & value to 0%.
        */
        progress_bar.style.width = "0%";
        update_progress_bar();
    }
});