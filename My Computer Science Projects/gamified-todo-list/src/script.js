// /*
//     Get references to:
//     - todo list container
//     - todo input field
//     - add todo button
//     - clear all todos button
//     - progress bar
//     - progress percentage
// */
// const todo_list_container = document.getElementById("todo-list-container");
// const todo_input = document.getElementById("todo-input");
// const add_todo_button = document.getElementById("add-todo-button");
// const clear_all_todos_button = document.getElementById("clear-all-todos-button");
// const progress_bar = document.getElementById("progress-bar");
// const progress_percentage = document.getElementById("progress-percentage");

// /*
//     Update the progress bar initially.
// */
// update_progress_bar();

// /*
//     function get_formatted_timestamp()
//     - returns formatted string of current time
// */
// function get_formatted_timestamp() {
//     const date = new Date();
//     const hours = date.getHours().toString().padStart(2, "0");
//     const minutes = date.getMinutes().toString.padStart(2, "0");
//     const seconds = date.getSeconds().toString().padStart(2, "0");
//     return `${hours}:${minutes}:${seconds}`;
// }

// /*
//     function update_progress_bar()
//     - updates/modifies progress bar width & percentage based on completion ratio.
// */
// function update_progress_bar() {
//     const number_completed_tasks = todo_list_container.querySelectorAll(".completed").length;
//     const number_total_tasks = todo_list_container.querySelectorAll("LI").length;
//     /*
//         Check if there are any tasks...
//     */
//     if (number_total_tasks === 0) {
//         /*
//             Set progress to 0 and display default percentage.
//         */
//         const progress = 0;
//         progress_percentage.textContent = `${progress.toFixed(1)}%`;
//         if (progress >= 80) {
//             progress_percentage.style.color = "#4caf50";
//         } else {
//             progress_percentage.style.color = "crimson";
//         }
//     } else {
//         /*
//             Calculate the progress percentage.
//         */
//         const progress = (number_completed_tasks / number_total_tasks) * 100;
//         /*
//             Update the progress bar width.
//         */
//         progress_bar.style.width = `${progress}`;
//         /*
//             Update the progress percentage text and styling.
//         */
//         progress_percentage.textContent = `${progress.toFixed(1)}%`;
//         /*
//             Update the color of the percentage text based on progress.
//         */
//         if (progress >= 80) {
//             progress_percentage.style.color = "#4caf50";
//         } else {
//             progress_percentage.style.color = "crimson";
//         }
//     }
// }

// /*
//     Add an event listener to the add_todo_button.
// */
// add_todo_button.addEventListener("click", function() {
//     /*
//         Get the value entered in the input field.
//     */
//     const new_todo_text = todo_input.value;
//     /*
//         Check if the input field is empty.
//     */
//     if (new_todo_text.trim() === "") {
//         alert("Please enter a valid task!");
//         return;
//     }
//     /*
//         Generate a timestamp for the new todo/task.
//     */
//     const timestamp = get_formatted_timestamp();
//     /*
//         Create a new list item element for the new task.
//     */
//     const new_todo_item = document.createElement("LI");
//     new_todo_item.classList.add("todo-item");
//     new_todo_item.textContent = new_todo_text;
//     const timestamp_element = document.createElement("span");
//     timestamp_element.classList.add("timestamp");
//     timestamp_element.textContent = timestamp;
//     new_todo_item.appendChild(timestamp_element);
//     /*
//         Add the new todo list item to the todo-list-container and update progress bar.
//     */
//     todo_list_container.appendChild(new_todo_item);
//     update_progress_bar();
//     /*
//         Clear the todo input field for the next task.
//     */
//     todo_input.value = "";
// });

// /*
//     Add an event listener to the clear_all_todos_button.
// */
// clear_all_todos_button.addEventListener("click", function() {
//     /*
//         Confirm with the user before clearing all tasks.
//     */
//     if (confirm("Are you sure you want to clear all tasks?")) {
//         /*
//             Remove all todo list items from the todo-list-container.
//         */
//         const todo_items = todo_list_container.querySelectorAll("LI");
//         /*
//             Loop through each list item and remove it.
//         */
//         for (let i = 0; i < todo_items.length; i++) {
//             todo_list_container.removeChild(todo_items[i]);
//         }
//         /*
//             Reset the progress bar & percentage with width & value to 0%.
//         */
//         progress_bar.style.width = "0%";
//         update_progress_bar();
//     }
// });

// /*
//     Add an event listener to each todo_list_container LI.
// */
// todo_list_container.addEventListener("click", function(event) {
//     /*
//         Check if the clicked element is a list item.
//     */
//     if (event.target.tagName == "LI") {
//         /*
//             Toggle a class on the clicked list item to visually mark it as completed.
//         */
//         event.target.classList.toggle("completed");
//         update_progress_bar();
//     }
// });

/*
    Get references to the input field and button elements.
*/
const todoInput = document.getElementById("todo-input");
const addButton = document.getElementById("add-todo-button");
const clearAllButton = document.getElementById("clear-all-todos-button");

/*
    Add an event listener to the addButton click.
*/
addButton.addEventListener("click", function() {
    /*
        Get the value entered in the input field.
    */
    const newTodoText = todoInput.value;
    /*
        Check if the input field is empty.
    */
    if (newTodoText.trim() === "") {
        alert("Please enter a task!");
        return;
    }
    /*
        Generate timestamp
    */
    const timestamp = getFormattedTimestamp();
    /*
        Create a new list item element for the new task.
    */
    const newTodoItem = document.createElement("li");
    newTodoItem.classList.add("todo-item");
    newTodoItem.textContent = newTodoText;
    const timestampElement = document.createElement("span");
    timestampElement.classList.add("timestamp");
    timestampElement.textContent = timestamp;
    newTodoItem.appendChild(timestampElement);
    /*
        Add the new list item to the to-do list container and update progress bar.
    */
    const todoList = document.getElementById("todo-list-container");
    todoList.appendChild(newTodoItem);
    updateProgressBar();
    /*
        Clear the input field for the next task.
    */
    todoInput.value = "";
});

/*
    Add an event listener to the clearAllButton click.
*/
clearAllButton.addEventListener("click", function() {
    /*
        Confirm with the user before clearing all tasks.
    */
    if (confirm("Are you sure you want to clear all tasks?")) {
        /*
            Remove all list items from the to-do list container.
        */
        const todoItems = todoList.querySelectorAll("LI");
        /*
            Loop through each list item and remove it.
        */
        for (let i = 0; i < todoItems.length; i++) {
            todoList.removeChild(todoItems[i]);
        }
        /*
            Reset the progres bar with width to 0.
        */
        const progressBar = document.getElementById("progress-bar");
        progressBar.style.width = "0%";
        updateProgressBar();
    }
});

/*
    Get references to the progress bar element and the list container
*/
const progressBar = document.getElementById("progress-bar");
const todoList = document.getElementById("todo-list-container");

/*
    Function to update the progress bar width based on completion ratio.
*/
function updateProgressBar() {
    const completedTasks = todoList.querySelectorAll(".completed").length;
    const totalTasks = todoList.querySelectorAll("LI").length;
    /*
        Check if there are any tasks.
    */
    if (totalTasks === 0) {
        /*
            Set progress to 0 and display default percentage.
        */
        const progress = 0;
        const progressPercentageElement = document.getElementById("progress-percentage");
        progressPercentageElement.textContent = `${progress.toFixed(1)}%`;
        if (progress >= 80) {
            // progressPercentageElement.classList.add("completed-percentage");
            progressPercentageElement.style.color = "#4CAF50";
        } else {
            // progressPercentageElement.classList.remove("completed-percentage");
            progressPercentageElement.style.color = "crimson";
        } 
    } else {
        /*
            Calculate the progress percentage.
        */
        const progress = (completedTasks / totalTasks) * 100;
        /*
            Update the progress bar width.
        */
        progressBar.style.width = `${progress}%`;
        /*
            Update the percentage text and styling.
        */
        const progressPercentageElement = document.getElementById("progress-percentage");
        progressPercentageElement.textContent = `${progress.toFixed(1)}%`;
        /*
            Update the color of the percentage text based on progress.
        */
        // if (progress === 100) {
        //     progressPercentageElement.classList.add("completed-percentage");
        // } else if (progress >= 50) {
        //     progressPercentageEl ement.classList.remove("completed-percentage");
        //     progressPercentageElement.classList.add("completed-half-percentage");
        // } else {
        //     progressPercentageElement.classList.remove("completed-half-percentage");
        //     progressPercentageElement.classList.remove("completed-percentage");
        // }
        if (progress >= 80) {
            // progressPercentageElement.classList.add("completed-percentage");
            progressPercentageElement.style.color = "#4CAF50";
        } else {
            // progressPercentageElement.classList.remove("completed-percentage");
            progressPercentageElement.style.color = "crimson";
        }
    }
}

/*
    Update the progress bar initially.
*/
updateProgressBar();

/*
    Add an event listener to the to-do list container.
    - update the progress bar whenever a task is marked as completed.
*/
todoList.addEventListener("click", function(event) {
    /*
        Check if the clicked element is a list item.
    */
    if (event.target.tagName == "LI") {
        /*
            Toggle a class on the clicked list item to visually mark it as completed.
        */
        event.target.classList.toggle("completed");
        updateProgressBar();
    }
});

/*
    Function for formatted timestamp generation.
*/
function getFormattedTimestamp() {
    const date = new Date();
    const hours = date.getHours().toString().padStart(2, "0");
    const minutes = date.getMinutes().toString().padStart(2, "0");
    const seconds = date.getSeconds().toString().padStart(2, "0");
    return `${hours}:${minutes}:${seconds}`;
}