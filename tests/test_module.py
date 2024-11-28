# %% Functions
from test_package import add, add_with_arguments, mul, divide, print_dict

add(1, 2)

add_with_arguments(i=4, j=6)

add_with_arguments(i=4)

res = mul(3, 4)
type(res)

res = mul(3.2, 4.9)
type(res)

divide(5, 2)

divide(5.0, 2)

print_dict({1: "a"})

# %% Lists and vectors
import numpy as np
from test_package import double_vector, double_vectorized, append_1, MyClass

a = [1, 2, 3, 4]
double_vector(a)

double_vectorized(a)

a2 = np.array([1, 2, 3, 4, 5, 6], dtype=np.float64)
double_vector(a2)

double_vectorized(a2)

double_vectorized([[1, 2, 3], [4, 5, 6]])

# %% Copy values
b = [1, 2, 3]
append_1(b)

c = MyClass()
c.contents = [5, 6]
c.contents.append(4)
c.contents

# from test_package import VectorInt
# c = MyClass()
# c.contents = VectorInt([5, 6])
# c.contents.append(7)

# %% Opaque types
from test_package import VectorInt, append_1

v = VectorInt()
v.append(1)
append_1(v)

v
# %% Classes
from test_package import Pet, Dog, pet_store, PolymorphicPet, PolymorphicDog, pet_store2

parrot = Pet("Parrot")
parrot.pet(3)
parrot

dog = Dog("Baldo")
dog.pet(2)
dog.bark()

isinstance(dog, Pet)

molly = pet_store()
molly.bark()


# Polymorphism
polymorphic_dog = pet_store2()
type(polymorphic_dog)

polymorphic_dog.bark()


# %% Container
from test_package import Container

container = Container()
container[2].data.value1 = 4
container[2]


# %% Advanced classes
from test_package import Animal, Cat, make_animal_sound

d = Cat()
make_animal_sound(d)


class MyDog(Animal):
    def __init__(self):
        super().__init__()  # <-- Important!!

    def make_sound(self, times):
        return "Woof! " * times


d2 = MyDog()
make_animal_sound(d2)


# %%
from test_package import list_dir_from_python
import glob

glob.glob("**/*.cpp")

list_dir_from_python("**/*.cpp", True)

# %%
