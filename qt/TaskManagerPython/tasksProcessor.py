from datetime import datetime

def calcDeadlineStatus(deadline, current_date):
    deadlineStatusList = [
        (30, "More than a month left"),
        (14, "Two weeks left"),
        (7, "One week left"),
        (3, "Less than a week left"),
        (1, "Less than a day left"),
        (0, "Deadline is today"),
        (-1, "Deadline has passed")
    ]
    #detetimeformat is yyyy-MM-dd-hh-mm-ss
    dtTypeDeadline = datetime(*map(int, deadline.split('-')))
    dtTypeCurrentDate = datetime(*map(int, current_date.split('-')))
    
    days_difference = (dtTypeDeadline - dtTypeCurrentDate).days
    
    # Determine the appropriate status based on the difference in days
    for threshold, status in deadlineStatusList:
        if days_difference >= threshold:
            return status
    return deadlineStatusList[-1][1]  # Return the last status if none of the deadlineStatusList match

def updDeadlineStatus(tasksList, currDateTime):
    for i in tasksList:
        temp = list(i)  # Convert tuple to list to make it mutable
        temp[7] = calcDeadlineStatus(temp[6], currDateTime)
        tasksList[tasksList.index(i)] = tuple(temp)  # Convert list back to tuple
    return tasksList
    
    
    
# deadlineStatusList = [
#     (30, "More than a month left"),
#     (14, "Two weeks left"),
#     (7, "One week left"),
#     (3, "Less than a week left"),
#     (1, "Less than a day left"),
#     (0, "Deadline is today"),
#     (-1, "Deadline has passed")
# ] 
# a = calcDeadlineStatus("2024-06-24-15-49-46", "2024-02-01-10-00-00")

# print(a)

