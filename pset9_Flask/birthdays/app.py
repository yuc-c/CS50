import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

app = Flask(__name__)

app.config["TEMPLATES_AUTO_RELOAD"] = True

db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        name = request.form.get("name")
        if not name:
            return redirect("/")

        month = request.form.get("month")
        if not month:
            return redirect("/")

        day = request.form.get("day")
        if not day:
            return redirect("/")
        try:
            month = int(month)
            day = int(day)
        except ValueError:
            return redirect("/")

        if day < 1 or day > 31:
            return redirect("/")

        db.execute(
            "INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)",
            name, month, day
        )

        return redirect("/")

    else:
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)


