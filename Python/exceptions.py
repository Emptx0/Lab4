class MyBaseException(Exception):
    def __init__(self, error_message=None):
        self.error_message = error_message

    def __str__(self):
        return f"MyBaseException\n{self.error_message}"


class ChoiceError(MyBaseException):
    def __str__(self):
        return "Invalid choice"


class ListException(MyBaseException):
    def __str__(self):
        return "Mushroom list is empty!"
