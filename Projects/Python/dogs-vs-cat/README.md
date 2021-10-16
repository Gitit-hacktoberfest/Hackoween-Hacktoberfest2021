# dogs-vs-cat
A simple classifier using TF2 using the kaggle competition data set(a little late for that)  
[DATASET HERE](https://www.kaggle.com/c/dogs-vs-cats/data)  
Got about 73% accuracy on validation data set.  
model have been saves and uploaded  
Try and predict some  
```pyhon
from tensorflow.keras.model import load_models
model=load_model("model")
pred=model.predict(pred_datat)
```

Note::input_shape=(64,64,3) so pre-process according to the requirement  
✌✌

