import exceptions


class Basket:
    def __init__(self):
        self._items = []

    def add_item(self, item):
        self._items.append(item)

    def calculate_result(self):
        if not self._items:
            raise exceptions.ListException()
        else:
            eatable_count = 0
            treatment_time = 0
            for item in self._items:
                if item.is_eatable():
                    eatable_count += 1
                else:
                    treatment_time += item.get_treatment()
            print(f"Eatable percent: {eatable_count / len(self._items) * 100}%")
            print(f"Treatment time: {treatment_time} minutes\n")

        self._items = []  # очистка кошику після розрахунку
