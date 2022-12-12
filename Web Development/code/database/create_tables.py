import sqlite3


connection = sqlite3.connect('data.db')

cursor = connection.cursor()
cursor.execute("PRAGMA foreign_keys = ON")



create_table = """CREATE TABLE IF NOT EXISTS user 
                (
                name text,
                siape_pk INTEGER PRIMARY KEY, 
                password text, 
                level text)"""
cursor.execute(create_table)

create_table = """CREATE TABLE IF NOT EXISTS subject 
                (subject_code_pk INTEGER PRIMARY KEY,
                name text, 
                semester INTEGER,
                workload INTEGER, 
                description text)"""
cursor.execute(create_table)

create_table = """CREATE TABLE IF NOT EXISTS topic 
                (topic_code_pk INTEGER, 
                name text, 
                description text,
                subject_fk INTEGER,
                PRIMARY KEY (topic_code_pk),
                FOREIGN KEY (subject_fk)
                    REFERENCES subject (subject_code_pk)
                    ON DELETE CASCADE
                    ON UPDATE NO ACTION

                )"""
cursor.execute(create_table)

create_table = """CREATE TABLE IF NOT EXISTS relationship 
                (relationship_code_pk INTEGER PRIMARY KEY, 
                description text,
                subject_1_fk INTEGER NOT NULL,
                topic_1_fk INTEGER NOT NULL,
                subject_2_fk INTEGER NOT NULL,
                topic_2_fk INTEGER NOT NULL,
                FOREIGN KEY (topic_1_fk)
                    REFERENCES topic (topic_code_pk)
                    ON DELETE CASCADE
                    ON UPDATE NO ACTION,
                FOREIGN KEY (topic_2_fk)
                    REFERENCES topic (topic_code_pk)
                    ON DELETE CASCADE
                    ON UPDATE NO ACTION,
                FOREIGN KEY (subject_1_fk)
                    REFERENCES subject (subject_code_pk)
                    ON DELETE CASCADE
                    ON UPDATE NO ACTION,
                FOREIGN KEY (subject_2_fk)
                    REFERENCES subject (subject_code_pk)
                    ON DELETE CASCADE
                    ON UPDATE NO ACTION

                )"""
cursor.execute(create_table)

create_table = """CREATE TABLE IF NOT EXISTS prerequisite 
                (prerequisite_code_pk INTEGER PRIMARY KEY, 
                description text,
                subject_fk INTEGER,
                subject_requirement_fk INTEGER,
                FOREIGN KEY (subject_fk)
                    REFERENCES subject (subject_code_pk)
                    ON DELETE CASCADE
                    ON UPDATE NO ACTION,
                FOREIGN KEY (subject_requirement_fk)
                    REFERENCES subject (subject_code_pk)
                    ON DELETE CASCADE
                    ON UPDATE NO ACTION
        

                )"""
cursor.execute(create_table)


# cursor.execute("""INSERT INTO user VALUES(NULL, "douglas", "douglasgondim@gmail.com", "123", "user")""")
# print(cursor.execute("""SELECT * from user """))
connection.commit()
connection.close()
