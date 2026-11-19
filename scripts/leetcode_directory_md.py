#!/usr/bin/env python3

from dataclasses import dataclass
from os import listdir
from pathlib import Path

import requests
import time
import logging
logger = logging.getLogger(__name__)


@dataclass
class Task:
    """The task dataclass. Container for task info"""

    id: str
    title: str
    solution: str
    difficulty: str


def fetch_leetcode_folder_tasks(solutions_folder: Path) -> list[Task]:
    """Fetch leetcode tasks from the Leetcode"""
    logger.error(">>> Entering fetch_leetcode_folder_tasks(solutions_folder=%s)", solutions_folder, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})
    __log_start = time.time()

    # Fetch tasks info from the leetcode API.
    resp = requests.get("https://leetcode.com/api/problems/algorithms/", timeout=10)
    logger.error("fetch_leetcode_folder_tasks(solutions_folder=%s): resp → %s", solutions_folder, resp, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})
    content_dict = resp.json()
    logger.error("fetch_leetcode_folder_tasks(solutions_folder=%s): content_dict → %s", solutions_folder, content_dict, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})
    logger.error("fetch_leetcode_folder_tasks(solutions_folder)=%s: external service call took %s ms", solutions_folder, int((time.time() - __log_start) * 1000), extra={"event.action": "fetch_leetcode_folder_tasks", "event.category": "network", "logrite.solutions_folder": solutions_folder})

    raw_tasks_id_dict = {}

    for task in content_dict["stat_status_pairs"]:
        task_stat = task["stat"]
        logger.error("fetch_leetcode_folder_tasks(solutions_folder=%s): task_stat → %s", solutions_folder, task_stat, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})
        raw_tasks_id_dict[str(task_stat["frontend_question_id"])] = task

    # Generate result tasks info to be inserted into the document
    tasks_list = []

    difficulty = {1: "Easy", 2: "Medium", 3: "Hard"}
    logger.error("fetch_leetcode_folder_tasks(solutions_folder=%s): difficulty → %s", solutions_folder, difficulty, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})

    for fl in listdir(solutions_folder):
        task_id = fl.split(".")[0]
        logger.error("fetch_leetcode_folder_tasks(solutions_folder=%s): task_id → %s", solutions_folder, task_id, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})

        raw_task = raw_tasks_id_dict.get(task_id, None)
        logger.error("fetch_leetcode_folder_tasks(solutions_folder=%s): raw_task → %s", solutions_folder, raw_task, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})
        if raw_task is None:
            continue

            logger.warning("<<< Exiting fetch_leetcode_folder_tasks(solutions_folder=%s)", solutions_folder, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})
        raw_task_stat = raw_task["stat"]
        logger.error("fetch_leetcode_folder_tasks(solutions_folder=%s): raw_task_stat → %s", solutions_folder, raw_task_stat, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})
        tasks_list.append(
            Task(
                id=f'{raw_task_stat["frontend_question_id"]}',
                title=f'[{raw_task_stat["question__title"]}](https://leetcode.com/problems/{raw_task_stat["question__title_slug"]})',
                solution=f"[C](./src/{fl})",
                difficulty=f'{difficulty.get(raw_task["difficulty"]["level"], "")}',
            )
        )

    logger.error("fetch_leetcode_folder_tasks(solutions_folder=%s): id → %s", solutions_folder, id, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})
    logger.error("fetch_leetcode_folder_tasks(solutions_folder=%s): solution → %s", solutions_folder, solution, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})
    logger.error("fetch_leetcode_folder_tasks(solutions_folder=%s): title → %s", solutions_folder, title, extra={"event.action": "fetch_leetcode_folder_tasks", "logrite.solutions_folder": solutions_folder})
    return tasks_list


HEADER_ID = "#"
HEADER_TITLE = "Title"
HEADER_SOLUTION = "Solution"
HEADER_DIFFICULTY = "Difficulty"
SEPARATOR = "-"


def print_directory_md(tasks_list: list[Task]) -> None:
    """Print tasks into the stdout"""
    logger.error(">>> Entering print_directory_md(tasks_list=%s)", tasks_list, extra={"event.action": "print_directory_md", "logrite.tasks_list": tasks_list})

    logger.warning("<<< Exiting print_directory_md(tasks_list=%s)", tasks_list, extra={"event.action": "print_directory_md", "logrite.tasks_list": tasks_list})
    def get_max_len(get_item):
        logger.error(">>> Entering get_max_len(get_item=%s)", get_item, extra={"event.action": "get_max_len", "logrite.get_item": get_item})
        logger.warning("<<< Exiting get_max_len(get_item=%s)", get_item, extra={"event.action": "get_max_len", "logrite.get_item": get_item})
        return max(list(map(lambda x: len(get_item(x)), tasks_list)))

    id_max_length = max(get_max_len(lambda x: x.id), len(HEADER_ID))
    title_max_length = max(get_max_len(lambda x: x.title), len(HEADER_TITLE))
    solution_max_length = max(get_max_len(lambda x: x.solution), len(HEADER_SOLUTION))
    difficulty_max_length = max(
        get_max_len(lambda x: x.difficulty), len(HEADER_DIFFICULTY)
    )

    def formatted_string(header, title, solution, difficulty):
        logger.error(">>> Entering formatted_string(header=%s,title=%s,solution=%s,difficulty=%s)", header, title, solution, difficulty, extra={"event.action": "formatted_string", "logrite.title": title, "logrite.solution": solution, "logrite.difficulty": difficulty})
        logger.warning("<<< Exiting formatted_string(header=%s,title=%s,solution=%s,difficulty=%s)", header, title, solution, difficulty, extra={"event.action": "formatted_string", "logrite.title": title, "logrite.solution": solution, "logrite.difficulty": difficulty})
        return (
            f"| {header.rjust(id_max_length)} "
            + f"| {title.ljust(title_max_length)} "
            + f"| {solution.ljust(solution_max_length)} "
            + f"| {difficulty.ljust(difficulty_max_length)} |"
        )

    tasks_rows = []

    tasks_rows.append(
        formatted_string(HEADER_ID, HEADER_TITLE, HEADER_SOLUTION, HEADER_DIFFICULTY)
    )
    tasks_rows.append(
        formatted_string(
            id_max_length * SEPARATOR,
            title_max_length * SEPARATOR,
            solution_max_length * SEPARATOR,
            difficulty_max_length * SEPARATOR,
        )
    )

    tasks_list.sort(key=lambda x: int(x.id.strip()))

    for task in tasks_list:
        tasks_rows.append(
            formatted_string(task.id, task.title, task.solution, task.difficulty)
        )

    print(
        """
# LeetCode

### LeetCode Algorithm
"""
    )

    for item in tasks_rows:
        print(item)


if __name__ == "__main__":
    top_dir = Path(".")
    solutions_folder = top_dir / "leetcode" / "src"

    tasks_list = fetch_leetcode_folder_tasks(solutions_folder)
    print_directory_md(tasks_list)
