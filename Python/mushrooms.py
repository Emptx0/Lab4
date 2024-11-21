from abc import ABC, abstractmethod
from enum import Enum, auto


class MushroomType(Enum):
    POISONOUS = auto()
    EATABLE = auto()


class Mushroom(ABC):
    def __init__(self, name):
        self._name = name

    @abstractmethod
    def get_name(self) -> str:
        pass


class EatableMushroom(Mushroom):
    def __init__(self, name):
        super().__init__(name)
        self._eatable = True

    def __str__(self):
        return f"{self._name}, true, 0 minutes"

    def get_name(self):
        return self._name

    def is_eatable(self):
        return self._eatable


class PoisonousMushroom(Mushroom):
    def __init__(self, name, treatment: int):
        super().__init__(name)
        self._eatable = False
        self._treatment = treatment

    def __str__(self):
        return f"{self._name}, false, {self._treatment} minutes"

    def get_name(self):
        return self._name

    def get_treatment(self):
        return self._treatment

    def is_eatable(self):
        return self._eatable


class MushroomFactory:
    @staticmethod
    def create_mushroom(context):
        if context.mushroom_type == MushroomType.EATABLE:
            return EatableMushroom(context.name)
        elif context.mushroom_type == MushroomType.POISONOUS:
            return PoisonousMushroom(context.name, context.treatment)
        else:
            raise ValueError(f"Unknown mushroom type: {context.mushroom_type}!")


class MushroomContext:
    def __init__(self, name, eatable, treatment: int):
        self.mushroom_type = MushroomType.EATABLE if eatable else MushroomType.POISONOUS
        self.name = name
        self.treatment = treatment
