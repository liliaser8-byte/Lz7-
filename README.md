**Звіт про виконання практичної роботи №7**

**Виконала:** студентка 4 курсу СОМ, Серветнік Лілія Ярославівна 

**Тема роботи: Реалізація черги.**

**Мета роботи:** *ознайомитися з основами роботи з чергою у Windows Forms за допомогою
класу System::Collections::Generic::Queue<T>, у C++/CLI, вивчити основні
операції: додавання, видалення, перегляд елементів, перевірка на порожність і
очищення черги.*

**Виконання завдань**

**Завдання 1. Розробити програму для створення та управління чергою,
що містить цілі числа, та виконати над ним основні операції.**


*Програмний код:*

```cpp
		System::Collections::Generic::Queue<int> numbersQueue;
		System::Collections::Generic::Queue<int> myQueue1;
		System::Collections::Generic::Queue<String^>StrQueue;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		numbersQueue.Enqueue(10);
		numbersQueue.Enqueue(20);
		numbersQueue.Enqueue(30);

		textBox1->Clear();
		for each (int number in numbersQueue) {
			textBox1->AppendText(number.ToString() + "\r\n");
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int number;
	number = Convert::ToInt32(textBox2->Text);

	numbersQueue.Enqueue(number);

	textBox1->Clear();

	for each (int num in numbersQueue) {
		textBox1->AppendText(num.ToString() + "\r\n");
	}
}
private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
if (checkedListBox1->GetItemChecked(0)) { // "Верхній елемент черги"
        if (numbersQueue.Count > 0) {
            MessageBox::Show("Поточний верхній елемент: " + numbersQueue.Peek().ToString());
        }
        else {
            MessageBox::Show("Черга порожня.");
        }
    }
    else if (checkedListBox1->GetItemChecked(1)) { // "Кількість елементів в черзі"
        int count = numbersQueue.Count;
        MessageBox::Show("Кількість елементів у черзі: " + count.ToString());
    }
    else if (checkedListBox1->GetItemChecked(2)) { // "Dequeue"
        if (numbersQueue.Count > 0) {
            int removedElement = numbersQueue.Dequeue();
            MessageBox::Show("Видалено верхній елемент: " + removedElement.ToString());
        }
        else {
            MessageBox::Show("Не можна видалити, черга порожня.");
        }
    }

    textBox1->Clear();

    for each (int num in numbersQueue) {
        textBox1->AppendText(num.ToString() + "\r\n");
    }
	   }
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Clear();
}

```
*Результат виконання:*
<img width="1112" height="652" alt="image" src="https://github.com/user-attachments/assets/5d23600e-5985-4f9e-9bb8-920a64525a0f" />
<img width="1176" height="712" alt="image" src="https://github.com/user-attachments/assets/749facc7-b509-411b-b601-c2df2755e568" />
<img width="1122" height="637" alt="image" src="https://github.com/user-attachments/assets/d36aa97d-188c-4958-9ab4-d1cc34e9c59e" />
<img width="830" height="557" alt="image" src="https://github.com/user-attachments/assets/a29dfbf4-fe2d-41d1-8269-9887d21117e0" />


**Завдання 2. Створити чергу для зберігання цілих чисел.**

*Програмний код:*

```cpp
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	int size = Convert::ToInt32(textBox3->Text);

	for (int i = 0; i < size; ++i) {
		int inputValue = Convert::ToInt32(Microsoft::VisualBasic::Interaction::InputBox("Елемент черги", "Введіть значення елементів черги", "", 200, 200));

		myQueue1.Enqueue(inputValue);
		listBox1->Items->Add(inputValue.ToString());
	}
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (myQueue1.Count > 0) {
		myQueue1.Dequeue();
		if (listBox1->Items->Count > 0) {
			listBox1->Items->RemoveAt(0);
		}
	}
	else {
		listBox1->Items->Add("Черга порожня");
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	int sum = 0;
	int evenCount = 0;

	for each(int value in myQueue1) {
		// Перевірка: чи число парне (value % 2 == 0) та чи належить діапазону від 10 до 20
		if (value % 2 == 0 && value >= 10 && value <= 20) {
			sum += value;
			evenCount++;
		}
	}

	if (evenCount > 0) {
		double average = (double)sum / evenCount;
		MessageBox::Show("Середнє значення парних чисел у діапазоні від 10 до 20: " + average.ToString(), "Результат");
	}
	else {
		MessageBox::Show("Немає парних чисел у діапазоні від 10 до 20.", "Результат");
	}
}

```

*Результат виконання:*
<img width="1217" height="677" alt="image" src="https://github.com/user-attachments/assets/b2288533-f938-433c-82ff-67fcce4990ba" />
<img width="806" height="520" alt="image" src="https://github.com/user-attachments/assets/23e9097c-302f-4610-ad0c-1e95ad376e17" />


**Завдання 3. Створити чергу для зберігання рядків.**

*Програмний код:*

```cpp

private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	int size = Convert::ToInt32(textBox4->Text);
	for (int i = 0; i < size; ++i) {
		String^ inputValue = Microsoft::VisualBasic::Interaction::InputBox("Введіть значення елементів черги", "Введіть значення елемента черги", "", 200, 200);
		StrQueue.Enqueue(inputValue);
		listBox2->Items->Add(inputValue);
	}
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	if (StrQueue.Count > 0) {
		StrQueue.Dequeue();
		if (listBox2->Items->Count > 0) {
			listBox2->Items->RemoveAt(0);
		}
	}
	else {
		listBox2->Items->Add("Черга порожня");
	}
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	int CountChars = 0;

	for (int i = 0; i < listBox2->Items->Count; i++) {
		String^ value = listBox2->Items[i]->ToString();
		CountChars += value->Length;
	}

	MessageBox::Show("Загальна кількість символів: " + CountChars, "Підсумок символів");
}
};
}

```

*Результат виконання:*
<img width="1125" height="715" alt="image" src="https://github.com/user-attachments/assets/a72adc46-664c-407b-86f0-b6fb9814071c" />
<img width="963" height="633" alt="image" src="https://github.com/user-attachments/assets/9edc7efb-cab3-4160-a815-6afb3b685d0e" />



**Висновок:** Під час виконання роботи було успішно досягнуто поставленої мети. Я ознайомилася з основами роботи зі структурою даних «черга» у середовищі Windows Forms за допомогою класу System::Collections::Generic::Queue<T> (C++/CLI). На практиці було реалізовано та засвоєно всі базові операції: додавання (Enqueue), видалення (Dequeue), перегляд елементів (Peek), перевірку черги на порожність та її повне очищення (Clear), що дозволило ефективно керувати даними за принципом FIFO.
