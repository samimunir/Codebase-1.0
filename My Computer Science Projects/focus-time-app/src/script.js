/*
    Select the task list element.
*/
const taskList = document.getElementById("task-list-items");

/*
    Select the input field for adding new tasks.
*/
const newTaskInput = document.getElementById("new-task");

/*
    Select the button for adding tasks.
*/
const addTaskButton = document.getElementById("add-task-button");

/*
    Function to add a new task to the list.
*/
function addTask() {
    /*
        Get the value entered in the input field.
    */
    const newTaskValue = newTaskInput.value.trim();
    /*
        Check if the new task value is empty.
    */
    if (newTaskValue) {
        /*
            Create a new list item element for the task.
        */
        const newTaskItem = document.createElement("LI");
        newTaskItem.textContent = newTaskValue;
        /*
            Optional: add functionality for marking tasks as complete.
            - e.g. --> checkbox
        */
        /*
            Add the new task item to the task list.
        */
        taskList.appendChild(newTaskItem);
        /*
            Clear the input field after adding the task.
        */
        newTaskInput.value = "";
    }
}

/*
    Add click event listener to the addTaskButton.
*/
addTaskButton.addEventListener("click", addTask);