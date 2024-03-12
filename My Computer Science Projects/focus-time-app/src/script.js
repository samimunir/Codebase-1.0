/*
    Declaring global variables.
    - used to control the state of the timer and keep track of the remaining time.
*/
/*
    flag to track if the timer is currently running.
*/
let isTimerRunning = false;
/*
    variable to store the interval ID for the timer.
*/
let timerInterval;
/*
    initial remaining time in seconds (25 minutes)
*/
let remainingTime = 25 * 60;

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
            Create a button element for deleting the task.
        */
        const deleteButton = document.createElement("button");
        deleteButton.textContent = "Delete";
        /*
            Add a click event listener to the delete button.
        */
        deleteButton.addEventListener("click", function() {
            /*
                Remove the task list item from the parent element (task list).
            */
            this.parentNode.remove();
        });
        /*
            Append the delete butotn to the new list item.
        */
        newTaskItem.appendChild(deleteButton);
        /*
            Optional: add functionality for marking tasks as complete.
            - e.g. --> checkbox
        */
        /*
            Create a checkbox element for marking the task as complete.
        */
        const taskCheckbox = document.createElement("input");
        taskCheckbox.type = "checkbox";
        /*
            Add a click event listener to the checkbox.
        */
        taskCheckbox.addEventListener("change", function() {
            /*
                Toggle the style of the list item to indicate completion (e.g., strikethrough).
            */
            this.parentNode.classList.toggle("completed");
        });
        /*
            Append the checkbox to the new list item.
        */
        newTaskItem.appendChild(taskCheckbox);
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

/*
    Function to update the timer display.
*/
function updateTimerDisplay() {
    const minutes = Math.floor(remainingTime / 60);
    const seconds = remainingTime % 60;
    // Format the time string with leading zeros for seconds.
    const formattedSeconds = seconds.toString().padStart(2, "0");
    document.getElementById("timer-minutes").textContent = minutes;
    document.getElementById("timer-seconds").textContent = formattedSeconds;
}