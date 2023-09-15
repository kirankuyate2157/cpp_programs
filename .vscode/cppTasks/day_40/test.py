from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas
from reportlab.platypus import SimpleDocTemplate, Paragraph
from reportlab.lib.styles import getSampleStyleSheet

# Create a PDF document
doc = SimpleDocTemplate(
    "Internship_Certificate_and_Recommendation.pdf", pagesize=letter)
story = []

# Define styles for text
styles = getSampleStyleSheet()
style = styles["Normal"]

# Replace placeholders with actual data
company_name = "GREENIE WEB PTE. LTD."
address = "531A Upper Cross Street, #04-95, Hong Lim Park, Singapore 051531"
tel = "Tel: (+65) 87981433"
internship_duration = "27 January 2022 to 27 April 2023"
student_name = "Kiran Kuyate"
certificate_text = f"""\
**Internship Certificate**

This is to certify that

**{student_name}**

was a Software Development Intern with {company_name}

from **{internship_duration}**.

Kiran has excelled in full-stack development with HTML, CSS, and JavaScript. For the frontend, Kiran researched and implemented new User Interface (UI) designs. At the backend, Kiran successfully developed an API for database connection. This eventually led to Kiran’s elevation to team lead where he coordinated with fellow members to further enhance the company’s digital product.

Kiran has been respectful and resourceful, demonstrating immense cultural sensitivity when working with our cross-border, multi-cultural team.

As such, it is my pleasure to present Kiran Kuyate with this
"""

# Add text to the PDF
story.append(Paragraph(company_name, style))
story.append(Paragraph(address, style))
story.append(Paragraph(tel, style))
story.append(Paragraph(internship_duration, style))
story.append(Paragraph(certificate_text, style))

# Build the PDF document
doc.build(story)

print("PDF generated successfully.")
