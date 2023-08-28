from reportlab.lib.pagesizes import letter
from reportlab.lib import colors
from reportlab.platypus import SimpleDocTemplate, Image, Spacer
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.platypus import Paragraph
from reportlab.lib.units import inch
import qrcode


def generate_certificate(user_name, course_name, unique_id, output_path):
    doc = SimpleDocTemplate(output_path, pagesize=letter)

    styles = getSampleStyleSheet()
    title_style = styles["Heading1"]
    normal_style = styles["Normal"]

    story = []

    # Background color
    background_color = colors.HexColor("#F5F5F5")
    story.append(Spacer(1, inch * 0.5))
    story.append(Image("logo.png", width=150, height=75, hAlign="RIGHT"))
    story.append(Spacer(1, inch * 0.5))

    # Certificate title
    title = "Certificate of Completion"
    story.append(Paragraph(title, title_style))
    story.append(Spacer(1, inch * 0.2))

    # User and course details
    user_details = f"This is to certify that <b>{user_name}</b> has successfully completed the course"
    course_details = f"<b>{course_name}</b> and is awarded this certificate with unique ID: <b>{unique_id}</b>."
    story.append(Paragraph(user_details, normal_style))
    story.append(Paragraph(course_details, normal_style))
    story.append(Spacer(1, inch * 0.8))

    # Generate QR code
    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_L,
        box_size=10,
        border=4,
    )
    qr.add_data(unique_id)
    qr.make(fit=True)

    qr_code_img = qr.make_image(fill_color="black", back_color="white")
    qr_code_img_path = "qr_code.png"
    qr_code_img.save(qr_code_img_path)

    # Add QR code to the certificate
    story.append(Image(qr_code_img_path, width=100,
                 height=100, hAlign="CENTER"))

    doc.build(story)


if __name__ == "__main__":
    user_name = "John Doe"
    course_name = "Web Development"
    unique_id = "CERT123456"
    output_path = "styled_certificate_with_qr.pdf"
    generate_certificate(user_name, course_name, unique_id, output_path)
