data = [(0,0,0),
        (0,1,0),
        (1,0,0),
        (1,1,1)]

# activation function
def step(x):
    return 1 if x > 0 else 0

# initial weights (random-ish)
w1, w2 = 0.0, 0.0
bias = 0.0
lr = 0.1  # learning rate

# training
for epoch in range(10):
    print(f"Epoch {epoch}")
    for x1, x2, y in data:
        z = x1*w1 + x2*w2 + bias
        y_pred = step(z)

        error = y - y_pred

        # update rule
        w1 += lr * error * x1
        w2 += lr * error * x2
        bias += lr * error

        print(f"  input=({x1},{x2}) pred={y_pred} error={error} bias={bias}")

print("\nTrained weights:")
print(w1, w2, bias)


def neuron(x1, x2):
    z = x1*w1 + x2*w2 + bias
    return step(z)

print(neuron(0, 0))  # 0
print(neuron(0, 1))  # 0
print(neuron(1, 0))  # 0
print(neuron(1, 1))  # 1

